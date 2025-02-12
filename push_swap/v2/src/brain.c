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
	if (e && !e->window)
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
	if (e_to && e_from && !e_from->window)
	{
		if (b->nb_element < 2 || (b->nb_element &&\
			((e_to->prev && e_from->ideal > e_to->ideal && e_from->ideal < e_to->prev->ideal) ||\
			(e_to->prev && e_from->ideal < b->min && e_to->prev->ideal == b->min) ||\
			(e_from->ideal > b->max && e_to->ideal == b->max))))
			return (1);
	}
	return (0);
}

void	update_voltigeur(t_all *all)
{
	if (all->e->a && all->e->a->next)
		all->e->a = all->e->a->next;
	else
		all->e->a = all->a->start;
	if (all->e->a_rev && all->e->a_rev->prev)
		all->e->a_rev = all->e->a_rev->prev;
	else
		all->e->a_rev = all->a->end;
	if (all->e->b && all->e->b->next)
		all->e->b = all->e->b->next;
	else
		all->e->b = all->b->start;
	if (all->e->b_rev && all->e->b_rev->prev)
		all->e->b_rev = all->e->b_rev->prev;
	else
		all->e->b_rev = all->b->end;
}

int	get_nearest_rotation_value(t_all *all)
{
	int	i;

	i = 0;
	while (i++ < (MAX(all->a->nb_element, all->b->nb_element)))
	{
		if (is_pushable2(all->e->a, all->e->b, all->b))
			return (i);
		if (is_pushable2(all->e->a_rev, all->e->b_rev, all->b))
			return (i);
		if (is_pushable(all->e->a, all->b))
			return (i);
		if (is_pushable(all->e->a_rev, all->b))
			return (i);
		if (is_pushable2(all->a->start, all->e->b, all->b))
			return (i);
		if (is_pushable2(all->a->start, all->e->b_rev, all->b))
			return (i);
		update_voltigeur(all);
	}
	return (0);
}

int	do_nearest_rotation(t_all *all)
{
	int	i;

	i = 0;
	while (i++ < (MAX(all->a->nb_element, all->b->nb_element)))
	{
		if (is_pushable2(all->e->a, all->e->b, all->b))
			return (double_rotate(all->a, all->b), i);
		if (is_pushable2(all->e->a_rev, all->e->b_rev, all->b))
			return (double_reverse_rotate(all->a, all->b), i);
		if (is_pushable(all->e->a, all->b))
			return (rotate(all->a), i);
		if (is_pushable(all->e->a_rev, all->b))
			return (reverse_rotate(all->a), i);
		if (is_pushable2(all->e->a_best, all->e->b, all->b))
			return (rotate(all->b), i);
		if (is_pushable2(all->e->a_best, all->e->b_rev, all->b))
			return (reverse_rotate(all->b), i);
		update_voltigeur(all);
	}
	return (0);
}

void	get_rotation(t_all *all)
{

	all->e->a_best = all->a->start;
	all->e->a = all->a->start;
	all->e->a_rev = all->a->end;
	all->e->b = all->b->start;
	all->e->b_rev = all->b->end;
	int	best;
	int	best_moment;
	int	moment;
	int	nb_rotate;
	int	rev;
	best = MAX(all->a->nb_element, all->b->nb_element);
	rev = 0;
	nb_rotate = 0;
	best_moment = 1;
	while (all->e->a != all->a->end)
	{	
		all->e->a_mem = all->e->a;
		all->e->a_rev_mem = all->e->a_rev;
		all->e->b = all->b->start;
		all->e->b_rev = all->b->end;
		moment = get_nearest_rotation_value(all);
		if (moment && moment + nb_rotate < best)
		{
			best = moment + nb_rotate;
			best_moment = moment;
			all->e->a_best = all->e->a_mem;
		}
		all->e->a = all->e->a_mem->next;
		if (all->e->a)
			all->e->a_rev = all->e->a->prev;
		nb_rotate++;
	}
	nb_rotate = 0;
	all->e->a = all->a->start;
	all->e->a_rev = all->a->end;
	while (all->e->a_rev != all->a->start)
	{	
		all->e->a_mem = all->e->a;
		all->e->a_rev_mem = all->e->a_rev;
		all->e->b = all->b->start;
		all->e->b_rev = all->b->end;
		moment = get_nearest_rotation_value(all);
		if (moment && moment + nb_rotate < best)
		{
			best = moment + nb_rotate;
			best_moment = moment;
			all->e->a_best = all->e->a_rev_mem;
			rev = 1;
		}
		all->e->a_rev = all->e->a_rev_mem->prev;
		if (all->e->a_rev)
			all->e->a = all->e->a_rev->next;
		nb_rotate++;
	}
	if (rev)
		while (all->a->end != all->e->a_best)
			reverse_rotate(all->a);
	else
		while (all->a->start != all->e->a_best)
			rotate(all->a);
	all->e->a = all->a->start;
	all->e->a_rev = all->a->end;
	all->e->b = all->b->start;
	all->e->b_rev = all->b->end;
	while (!is_pushable(all->a->start, all->b) && best_moment--)
		do_nearest_rotation(all);
}

void	get_best_move_to_b(t_all *all)
{
	if (all->a->start->ideal == all->a->start->next->ideal + 1)
	{
		swap(all->a);
		get_window(all->a);
	}
	if (is_pushable(all->a->start, all->b))
		push(all->a, all->b);
	else
		get_rotation(all);
}
int	have_not_windowed(t_stack *a)
{
	t_element *e;

	e = a->start;
	while (e)
	{
		if (!e->window)
			return (1);
		e = e->next;
	}
	return (0);
}

void	to_b_sorted(t_all *all)
{
	//while (all->a->nb_element > 3)
	while (have_not_windowed(all->a))
		get_best_move_to_b(all);
}

void	sort_stack(t_all *all)
{
	analyse(all->a);
//	print_results(all);
	to_b_sorted(all);
	print_results(all);
//	back_to_a(all);
//	print_results(all);
	return ;	
}
