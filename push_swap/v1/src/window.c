#include "push_swap.h"

static void	put_on_stack(t_element **stack, t_element *e)
{
	int	i;

	i = 0;
	while (stack[i] && stack[i]->ideal < e->ideal)
		i++;
	stack[i] = e;
	if (i)
		e->prev_window = stack[i - 1]; 
	else
		e->prev_window = NULL;
}

static void	mark_window(t_element **stack)
{
	t_element *e;
	while (*stack)
		stack++;
	e = *--stack;
	while (e)
	{
		e->window = 1;
		e = e->prev_window;
	}
}

void	get_window(t_stack *l)
{
	t_element	*stack[500];
	t_element	*i;
	int	on;
	
	ft_bzero(stack, 500 * sizeof(t_element *));
	on  = 1;
	i = l->start;
	while (i->ideal != 1)
		i = i->next;
	while (on || i->ideal != 1)
	{
		put_on_stack(stack, i);
		i = i->next;
		on = 0;
		if (!i)
			i = l->start;
	}
	mark_window(stack);
}

/*
void	get_window(t_stack *l1)
{
	t_element	*i;
	t_element	*start;
	t_element	*best;
	int			count;
	int			max;

	i = l1->start;
	max = 0;
	while (i)
	{

		start = i;
		count = 1;
		while (i->next && i->next->ideal >= i->ideal)
		{
			count++;
			i = i->next;
			if (!i->next && l1->start->ideal >= i->ideal)
			{
				i = l1->start;
				count++;
			}
		}
		if (count > max)
		{
			best = start;
			max = count;
		}
		i = start->next;
	}
	count = 0;
	while (count < max)
	{
		best->window = 1;
		if (best->next)
			best = best->next;
		else
			best = l1->start;
		count++;
	}
}
*/
