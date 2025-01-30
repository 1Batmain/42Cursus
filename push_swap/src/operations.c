#include "push_swap.h"

void	swap(t_stack *l)
{
	(*l->nb_op)++;
	t_element *temp;
	
	if (!l->start || !l->start->next)
		return ;
	temp = (l->start)->next;
	temp->prev = NULL;
	l->start->next = l->start->next->next;
	l->start->prev = temp;
	temp->next = l->start;
	l->start = temp;
	ft_printf("s\n");
	return ;
}

void	push(t_stack *a, t_stack *b)
{
	(*a->nb_op)++;
	t_element	*temp;

	if (!a->start)
		return ;
	push_max_min(a, b);
	temp = a->start->next;
	if (temp)
		temp->prev = NULL;
	if (b->nb_element > 0)
		b->start->prev = a->start;
	a->start->next = b->start;
	b->start = a->start;
	b->start->prev = NULL;
	a->start = temp;
	b->nb_element++;
	a->nb_element--;
	if (b->nb_element == 1)
		b->end = b->start;

	return ;
}

void	rotate(t_stack *l)
{
	(*l->nb_op)++;
	t_element	*temp;

	if (l->nb_element < 2)
		return ;
	temp = l->start->next;
	temp->prev = NULL;
	l->end->next = l->start;
	l->start->prev = l->end;
	l->start->next = NULL;
	l->end = l->start;
	l->start = temp;
	return ;
}

void	reverse_rotate(t_stack *l)
{
	(*l->nb_op)++;
	t_element 	*temp;

	if (l->nb_element < 2)
		return ;
	temp = l->end->prev;
	l->end->prev = NULL;
	l->end->next = l->start;
	l->start->prev = l->end;
	l->start = l->end;
	l->end = temp;
	l->end->next = NULL;


	return ;
}
