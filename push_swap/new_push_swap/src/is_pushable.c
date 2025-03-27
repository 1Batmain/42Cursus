/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pushable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:43:28 by bduval            #+#    #+#             */
/*   Updated: 2025/03/26 21:53:16 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_pushable_to_b(t_element *e, t_all *all)
{
	int	tolerance;

	tolerance = 0;
	if (e && !e->window)
	{
		if (all->b->nb_element < 2 || (all->b->nb_element && \
			((e->ideal > all->b->start->ideal - tolerance && \
			e->ideal < all->b->end->ideal + tolerance) || \
			(e->ideal < all->b->min && all->b->end->ideal == all->b->min) || \
			(e->ideal > all->b->max && all->b->start->ideal == all->b->max))))
			return (1);
	}
	return (0);
}

int	is_pushable_to_b2(t_element *e_from, t_element *e_to, t_all *all)
{
	int	tolerance;

	tolerance = 0;
	if (e_to && e_from && !e_from->window)
	{
		if (all->b->nb_element < 2 || (all->b->nb_element && \
			((e_to->prev && e_from->ideal > e_to->ideal - tolerance && \
			e_from->ideal < e_to->prev->ideal + tolerance) || \
			(e_to->prev && e_from->ideal < all->b->min && \
			e_to->prev->ideal == all->b->min) || \
			(e_from->ideal > all->b->max && e_to->ideal == all->b->max))))
			return (1);
	}
	return (0);
}

/*
int	is_pushable_to_b(t_element *e, t_all *all)
{
	if (e && !e->window)
	{
		if (all->b->nb_element < 2 || is_in_quartil(e, all->b->start, all))
			return (1);
	}
	return (0);
}

int	is_pushable_to_b2(t_element *e_from, t_element *e_to, t_all *all)
{
	if (e_to && e_from && !e_from->window)
	{
		if (all->b->nb_element < 2 || is_in_quartil(e_from, e_to, all))
			return (1);
	}
	return (0);
}

float	paow(float a)
{
	return (a * a);
}



int	ecart_type(t_element *e_from,  t_element *e_to, t_all *all)
{
	t_element	*e_rev;
	float	moyenne;
	float	squared_ecart;
	int		i;
	int		y;

	moyenne = e_from->ideal;
	if (e_to->prev)
		e_rev = e_to->prev;
	else
		e_rev = all->b->end;
	i = 1;
	while (i < 15)
	{
		moyenne += e_to->ideal + e_rev->ideal;
		e_to = e_to->next;
		if (!e_to)
			e_to = all->b->start;
		if (e_rev->prev)
			e_rev = e_rev->prev;
		else
			e_rev = all->b->end;
		i++;
	}
	y = 1;
	moyenne /= i * 2;
	squared_ecart = paow(e_from->ideal - moyenne);
	while (y != i)
	{
		squared_ecart += paow(e_to->ideal - moyenne) + paow(e_rev->ideal - moyenne);
		e_to = e_to->prev;
		if (!e_to)
			e_to = all->b->end;
		e_rev = e_rev->next;
		if(!e_rev)
			e_rev = all->b->start;
		y++;
	}
	squared_ecart /= i * 2;
	//printf("%f - %d\n", squared_ecart, all->b->nb_element);
	return (squared_ecart);


}

int	is_in_quart(t_element *e_from, t_element *e_to, t_all *all)
{
	int	trigger;

	trigger = 15000;
	if (ecart_type(e_from, e_to, all) < trigger)
		return (1);
	return (0);
}

int	is_pushable_to_b(t_element *e, t_all *all)
{
	if (e && !e->window)
	{
		if (all->b->nb_element < 2 || e->ideal > all->b->start->ideal - 5)
			return (1);
	}
	return (0);
}

int	is_pushable_to_b2(t_element *e_from, t_element *e_to, t_all *all)
{
	if (e_from && !e_from->window)
	{
		if (all->b->nb_element < 2 || e_from->ideal > e_to->ideal - 5)
			return (1);
	}
	return (0);

}
 */

int	is_within_current_chunk(t_all *all, t_element *e)
{
	int	chunk_size;

	if (!e)
		return (1);
	chunk_size = all->nb_element / all->nb_chunk;
	if (all->curr_chunk == all->nb_chunk && e->ideal >= chunk_size * \
			(all->curr_chunk - 1))
		return (1);
	if (all->curr_chunk == 1 && e->ideal <= chunk_size)
		return (1);
	if (e->ideal >= chunk_size * (all->curr_chunk -1) && e->ideal <= chunk_size \
			* all->curr_chunk)
		return (1);
	return (0);
}

int	is_pushable_to_a(t_element *e, t_all *all)
{
	if (e)
	{
		if (((e->ideal < all->a->start->ideal && \
				e->ideal > all->a->end->ideal) || \
			(e->ideal > all->a->max && all->a->end->ideal == all->a->max) || \
			(e->ideal < all->a->min && all->a->start->ideal == all->a->min)))
			return (1);
	}
	return (0);
}

int	is_pushable_to_a2(t_element *e_from, t_element *e_to, t_all *all)
{
	t_element	*e_to_prev;

	if (e_to->prev)
		e_to_prev = e_to->prev;
	else
		e_to_prev = all->a->end;
	if (e_to && e_from)
	{
		if (((e_from->ideal < e_to->ideal && \
			e_from->ideal > e_to_prev->ideal) || \
			(e_from->ideal > all->a->max && e_to->ideal == all->a->min) || \
			(e_from->ideal < all->a->min && e_to->ideal == all->a->min)))
			return (1);
	}
	return (0);
}
