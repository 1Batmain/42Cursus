/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:56:42 by bduval            #+#    #+#             */
/*   Updated: 2025/02/13 14:52:19 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	get_new_max(t_stack *a)
{
	t_element	*i;

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
	t_element	*i;

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

void	back_propagate(t_element *instant)
{
	t_element	*outfielder;

	outfielder = instant->prev;
	while (outfielder)
	{
		if (instant->value <= outfielder->value)
		{
			if (instant->ideal > outfielder->ideal)
				instant->ideal = outfielder->ideal;
			outfielder->ideal++;
		}
		outfielder = outfielder->prev;
	}
}

void	analyse(t_stack *l)
{
	t_element	*instant;
	int			pos;
	int			max;

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
