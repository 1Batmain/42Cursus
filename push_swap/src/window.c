#include "push_swap.h"

void	free_pile(t_pile *p)
{
	t_pile	*temp;

	while (p->prev_pile)
		p = p->prev_pile;
	while (p->prev)
		p = p->prev;
	while (p)
	{
		temp = p;
		if (p->next)
			p = p->next;	
		else
			p = p->next_pile;
		free(temp);
	}
}

int	new_pile(t_pile **p, t_element *e)
{
	t_pile	*new;

	new = (t_pile *)malloc(sizeof(t_pile));
	if (!new)}
		return (free_pile(*p), 1);
	while (*p && *p->next_pile)
		p = p->next_pile;
	new->element = e;
	new->next = NULL;
	new->prev = *p;
	if (*p)
	{
		new->next_pile = *p->next_pile;
		new->prev_pile = *p->prev_pile;
		*p->next = new;
	}
	else
	{
		new->next_pile = NULL;
		new->prev_pile = NULL;
		*p = new;
	}
}

void	get_window(t_stack *l)
{
	t_pile		*p;
	t_element	*i;
	int			on;

	i = l->start;
	while (i->ideal != 1)
		i = i->next;
	new_pile(&p, i);
	on = 1;
	while (on || i->ideal != 1)
	{
		while (p && p->next_pile && p->last->ideal <= i->ideal)
			p = p->next_pile;
		if (p->last->ideal > i->ideal)
			add_to(p, i);
		else
			new_pile(&p, i);
		on = 0;
		i = i->next;
		if (!i)
			i = l->start;
	}
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
