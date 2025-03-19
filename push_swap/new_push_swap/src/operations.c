/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:09:36 by bduval            #+#    #+#             */
/*   Updated: 2025/03/19 15:27:49 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	swap(t_stack *l, int print)
{
	t_element	*temp;

	(*l->nb_op)++;
	if (!l->start || !l->start->next)
		return ;
	temp = l->start;
	l->start = l->start->next;
	l->start->prev = NULL;
	temp->next = l->start->next;
	temp->prev = l->start;
	temp->next->prev = temp;
	l->start->next = temp;
	if (l->nb_element == 2)
		l->end = l->start->next;
	if (print)
		ft_printf("s%c\n", l->name);
	return ;
}

void	push(t_stack *a, t_stack *b, int print)
{
	t_element	*temp;

	(*a->nb_op)++;
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
	if (print)
		ft_printf("p%c\n", b->name);
	return ;
}

void	rotate(t_stack *l, int print)
{
	t_element	*temp;

	(*l->nb_op)++;
	if (l->nb_element < 2)
		return ;
	temp = l->start->next;
	temp->prev = NULL;
	l->end->next = l->start;
	l->start->prev = l->end;
	l->start->next = NULL;
	l->end = l->start;
	l->start = temp;
	if (print)
		ft_printf("r%c\n", l->name);
	return ;
}

void	reverse_rotate(t_stack *l, int print)
{
	t_element	*temp;

	(*l->nb_op)++;
	if (l->nb_element < 2)
		return ;
	temp = l->end->prev;
	l->end->prev = NULL;
	l->end->next = l->start;
	l->start->prev = l->end;
	l->start = l->end;
	l->end = temp;
	l->end->next = NULL;
	if (print)
		ft_printf("rr%c\n", l->name);
	return ;
}
