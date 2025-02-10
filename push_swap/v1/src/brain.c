#include "push_swap.h"

void	get_new_max(t_stack *a)
{
	t_element *i;

	a->max = a->max - 1;
	while (1)
	{
		i = a->start;
		while (i)
		{
			if (i->ideal == a->max)
				return ;
			i = i->next;
		}
		a->max--;
	}
}

void	get_new_min(t_stack *a)
{
	t_element *i;

	a->min = a->min + 1;
	while (1)
	{
		i = a->start;
		while (i)
		{
			if (i->ideal == a->min)
				return ;
			i = i->next;
		}
		a->min++;
	}
}

void	push_max_min(t_stack *a, t_stack *b)
{
	if (a->start->ideal == a->max)
	{
		if (b->max < a->start->ideal - 1)
			a->max--;
		else if (a->nb_element > 1)
			get_new_max(a);
	}
	if (a->start->ideal == a->min)
	{
		if (b->min > a->start->ideal + 1)
			a->min++;
		else if (a->nb_element > 1)
			get_new_min(a);
	}
	if (a->start->ideal > b->max)
		b->max = a->start->ideal;
	if (a->start->ideal < b->min)
		b->min = a->start->ideal;
	if (a->nb_element == 1)
	{
		a->min = 2147483647;
		a->max = -2147483648;
	}
}

t_element	*get_best(int target, t_stack *l)
{
	t_element *e;
	t_element *best;
	int	best_gap;
	int	curr_gap;

	e = l->start;
	best_gap = 2147483647;
	while (e)
	{
		if ((target < l->min && e->ideal == l->min) ||\
			(target > l->max && e->ideal == l->max))
			return (e);
		curr_gap = ABS(target - 1 - e->ideal);
		if (curr_gap < best_gap)
		{
			best_gap = curr_gap;
			best = e;
		}
		e = e->next;
	}
	return (best);
}

void	rotate_to(int target, t_stack *l)
{
	t_element *best;
	static int	mem;
	static int	dir;
	int	i;

	if (mem != target)
	{
		i = 0;
		best = get_best(target, l);
		while (best != l->start)
		{
			best = best->prev;
			i++;
		}
		if (i >= l->nb_element / 2)
			dir = -1;
		else
			dir = 1;
		mem = target;
	}
	if (dir == 1)
		rotate(l);
	else
		reverse_rotate(l);
}

int	get_next_moveable(t_stack *a, int *ideal)
{
	int	res;
	t_element *e_n;
	t_element *e_p;

	res = 1;
	e_n = a->start->next;
	e_p = a->end;
	*ideal = e_n->ideal;
	while (!e_n)
	{
		e_n = e_n->next;
		e_p = e_p->prev;
		res++;
		if (!e_n->window)
		{
			*ideal = e_n->ideal;
			return (res);
		}
		else if (!e_p->window)
		{
			*ideal = e_p->ideal;
			return (-res);
		}
	}
	return (res);
}

void	rotate_to_b(t_stack *a, t_stack *b)
{
	int	next_window;
	int	ideal;

	next_window = get_next_moveable(a, &ideal);
	if (b->start && next_window > 0 && ideal < b->start->ideal)
		double_rotate(a, b);
	else if (b->end && next_window < 0 && ideal > b->end->ideal)
		double_reverse_rotate(a, b);
	else if (next_window < 0)
		reverse_rotate(a);
	else
		rotate(a);
}

void	back_to_a(t_stack *l1, t_stack *l2)
{
	while (l2->nb_element > 0)
	{
		if ((l1->start->ideal == l1->end->ideal + 1) ||\
			(l1->start->ideal == 1 && l2->start->ideal < l1->max + 1) ||\
			(l2->nb_element == 1 && \
			((l2->start->ideal != l1->start->ideal - 1 && l2->start->ideal != l1->max + 1) || \
			(l2->start->ideal == l1->max + 1 && l1->start->ideal != l1->min))))
			rotate(l1);
		else
		{
			while ((l2->nb_element > 1 && l1->start->ideal != 1 &&\
						l1->start->ideal != l2->start->ideal + 1) ||\
					(l2->max > l1->max && l1->start->ideal == 1 && l2->start->ideal != l2->max))
				rotate(l2);
			while (l2->nb_element &&\
					(l1->start->ideal == l2->start->ideal + 1 ||\
					l1->end->ideal == l2->start->ideal - 1 ||\
					(l2->max > l1->max && l1->start->ideal == 1 && l2->start->ideal == l2->max)))
				push(l2, l1);
		}
	}
}

void	to_b_sorted(t_stack *l1, t_stack *l2)
{
	int	on;
	t_element *i;
	t_element *start;

	start = l1->start;
	on = 1;
	i = l1->start;
	while (on || i != start)
	{
		if (!i->window)
		{
			if (i == start)
				start = i->next;
			else
				on = 0;
			while (l2->nb_element >= 2 &&\
					!((i->ideal < l2->max && l2->max == l2->end->ideal) ||\
					(i->ideal > l2->min && l2->min == l2->start->ideal) ||\
					(i->ideal > l2->start->ideal && i->ideal < l2->end->ideal) ||\
					(i->ideal < l2->min && l2->end->ideal == l2->min) ||\
					(i->ideal > l2->max && l2->start->ideal == l2->max)))
				rotate_to(i->ideal, l2);
				//rotate(l2);
			push(l1, l2);
		}
		else
			rotate_to_b(l1, l2);
			//rotate(l1);
		i = l1->start;
	}
}

void	back_propagate(t_element *instant)
{
	t_element *outfielder;

	outfielder = instant->prev;
	while (outfielder)
	{
		if (instant->value <= outfielder->value)
		{
			if (instant->ideal > outfielder->ideal)
				instant->ideal = outfielder->ideal;
			outfielder->ideal++;
		}
		outfielder  = outfielder->prev;
	}
}

void	analyse(t_stack *l)
{
	t_element *instant;
	int	pos;
	int	max;

	pos = 1;
	instant = l->start;
	max = instant->value;
	while (instant)
	{
		instant->ideal = pos++;
		if (instant->value < max)
			back_propagate(instant);
		else
			max = instant->value;
		instant = instant->next;
	}
	l->min = 1;
	l->max = --pos;
	get_window(l);
}

void	sort_stack(t_stack *l1, t_stack *l2)
{
	analyse(l1);
	print_results(l1, l2);
	to_b_sorted(l1, l2);
	print_results(l1, l2);
	back_to_a(l1, l2);
	print_results(l1, l2);
	return ;	
}
