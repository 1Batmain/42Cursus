/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pushable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:43:28 by bduval            #+#    #+#             */
/*   Updated: 2025/02/13 14:46:54 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	is_pushable_to_b(t_element *e, t_stack *b)
{
	if (e && !e->window)
	{
		if (b->nb_element < 2 || (b->nb_element && \
			((e->ideal > b->start->ideal && e->ideal < b->end->ideal) || \
			(e->ideal < b->min && b->end->ideal == b->min) || \
			(e->ideal > b->max && b->start->ideal == b->max))))
			return (1);
	}
	return (0);
}

int	is_pushable_to_b2(t_element *e_from, t_element *e_to, t_stack *b)
{
	if (e_to && e_from && !e_from->window)
	{
		if (b->nb_element < 2 || (b->nb_element && \
			((e_to->prev && e_from->ideal > e_to->ideal && \
			e_from->ideal < e_to->prev->ideal) || \
			(e_to->prev && e_from->ideal < b->min && \
			e_to->prev->ideal == b->min) || \
			(e_from->ideal > b->max && e_to->ideal == b->max))))
			return (1);
	}
	return (0);
}

int	is_pushable_to_a(t_element *e, t_all *all)
{
	if (e)
	{
		if (e->ideal == all->a->start->ideal - 1 || \
			(e->ideal == all->b->max && \
			all->b->max > all->a->max && \
			all->a->start->ideal == all->a->min))
			return (1);
	}
	return (0);
}

int	is_pushable_to_a2(t_element *e_from, t_element *e_to, t_all *all)
{
	if (e_to && e_from)
	{
		if (e_from->ideal == e_to->ideal - 1 || \
			(e_from->ideal == all->b->max && all->b->max > all->a->max && \
			e_to->ideal == all->a->min))
			return (1);
	}
	return (0);
}
