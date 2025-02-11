  #include "push_swap.h"

int	is_fillable(t_stack *from, t_stack *to)
{
	if ((to->start->ideal != to->end->ideal - 1 && to->start->ideal != to->max) ||\
		(to->start->ideal == to->max && to->max < from->max) ||\
		(to->start->ideal == to->max && to->min > from->min))
		return (1);
	return (0);
}

int	is_element_fillable(t_stack *from, t_stack *to, t_element *e)
{
	if ((e->prev && e->ideal != e->prev->ideal - 1 && e->ideal != to->max) ||\
		(e->ideal == to->max && to->max < from->max) ||\
		(e->prev && e->prev->ideal == to->min && to->min > from->min))
		return (1);
	return (0);
}

int	is_pushable(t_element *e, t_stack *b)
{
	if (e)
	{
		if (b->nb_element < 2 || (b->nb_element &&\
			((e->ideal > b->start->ideal && e->ideal < b->end->ideal) ||\
			(e->ideal < b->min && b->end->ideal == b->min) ||\
			(e->ideal > b->max && b->start->ideal == b->max))))
			return (1);
	}
	return (0);
}

int	is_pushable2(t_element *e_from, t_element *e_to,  t_stack *b)
{
	if (e_to && e_from)
	{
		if (b->nb_element < 2 || (b->nb_element &&\
			((e_to->prev && e_from->ideal > e_to->ideal && e_from->ideal < e_to->prev->ideal) ||\
			(e_to->prev && e_from->ideal < b->min && e_to->prev->ideal == b->min) ||\
			(e_from->ideal > b->max && e_to->ideal == b->max))))
			return (1);
	}
	return (0);
}

void	get_nearest_fillable(t_all *all)
{
	t_element	*e_rotate;
	t_element	*e_rev_rotate;

	e_rotate = all->b->start;
	e_rev_rotate = all->b->start;
	while (1)
	{
		e_rotate = e_rotate->next;
		if (!e_rev_rotate->prev)
			e_rev_rotate = all->b->end;
		else
			e_rev_rotate = e_rev_rotate->prev;
		if (is_element_fillable(all->a, all->b, e_rotate))
			return (rotate(all->a));
	}
}

void	get_nearest_rotation(t_all *all)
{
	t_element	*e_from;
	t_element	*e_from_rev;
	t_element	*e_to;
	t_element	*e_to_rev;

	e_from = all->a->start->next;
	e_from_rev = all->a->end;
	e_to = all->b->start->next;
	e_to_rev = all->b->end;
	while (1)
	{
		if (is_pushable2(e_from, e_to, all->b))
			return (double_rotate(all->a, all->b));
		if (is_pushable2(e_from_rev, e_to_rev, all->b))
			return (double_reverse_rotate(all->a, all->b));
		if (is_pushable(e_from, all->b))
			return (rotate(all->a));
		if (is_pushable(e_from_rev, all->b))
			return (reverse_rotate(all->a));
		if (is_pushable2(all->a->start, e_to, all->b))
			return (rotate(all->b));
		if (is_pushable2(all->a->start, e_to_rev, all->b))
			return (reverse_rotate(all->b));
		if (e_from)
			e_from = e_from->next;
		if (e_from_rev)
			e_from_rev = e_from_rev->prev;
		if (e_to)
			e_to = e_to->next;
		if (e_to_rev)
			e_to_rev = e_to_rev->prev;
		//if (!(e_from && e_from_rev && e_to && e_to_rev))
		//	get_nearest_fillable(all);

	}
}
/*
void	get_nearest_rotation(t_stack *from, t_stack *to)
{
	t_element	*e_from_rotate;
	t_element	*e_from_rev_rotate;
	t_element	*e_to_rotate;
	t_element	*e_to_rev_rotate;

	e_from_rotate = from->start;
	e_from_rev_rotate = from->start;
	e_to_rotate = to->start;
	e_to_rev_rotate = to->start;
	while (1)
	{
		e_from_rotate = e_from_rotate->next;
		if (!e_from_rev_rotate->prev)
			e_from_rev_rotate = from->end;
		else
			e_from_rev_rotate = e_from_rev_rotate->prev;
		if (e_to_rotate)
			e_to_rotate = e_to_rotate->next;
		if (!e_to_rev_rotate->prev)
			e_to_rev_rotate = to->end;
		else
			e_to_rev_rotate = e_to_rev_rotate->prev;
		if (e_to_rotate || e_to_rev_rotate)
		{
			if (is_pushable2(e_from_rotate, e_to_rotate, to))
				return (double_rotate(from, to));
			if (is_pushable2(e_from_rev_rotate, e_to_rev_rotate, to))
				return (double_reverse_rotate(from, to));
		}
		if (is_pushable(e_from_rotate, to))
			return (rotate(from));
		if (is_pushable(e_from_rev_rotate, to))
			return (reverse_rotate(from));
	}
}
*/


void	get_best_rotation_to_b(t_all *all)
{
	//if (is_fillable(a, b))
		get_nearest_rotation(all);
	//else
	//	get_nearest_fillable(a, b);
}

void	get_best_move_to_b(t_all *all)
{
	if (all->a->start->ideal == all->a->start->next->ideal + 1)
		swap(all->a);
	if (is_pushable(all->a->start, all->b))
		push(all->a, all->b);
	else
		get_best_rotation_to_b(all);
}

void	to_b_sorted(t_all *all)
{
	while (all->a->nb_element > 3)
		get_best_move_to_b(all);
}

void	sort_stack(t_all *all)
{
	analyse(all->a);
	print_results(all);
	to_b_sorted(all);
	print_results(all);
//	back_to_a(all);
//	print_results(all);
	return ;	
}
