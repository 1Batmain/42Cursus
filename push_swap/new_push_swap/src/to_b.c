/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:36:47 by bduval            #+#    #+#             */
/*   Updated: 2025/03/26 22:43:54 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	moyenne_a(t_all *all)
{
	double		moyenne;
	t_element	*e;
	int			nb_element;

	moyenne = 0;
	nb_element = 0;
	e = all->a->start;
	while (e)
	{	
		if (!e->window)
		{
			moyenne += e->ideal;
			nb_element++;
		}
		e = e->next;
	}
	moyenne /= nb_element;
	if (all->nb_element <= 100)
		moyenne *= 2;
	return (moyenne);
}

static void	rotate_to_nearest(t_all *all)
{
	t_element	*fwd;
	t_element	*rvs;

	fwd = all->a->start->next;
	rvs = all->a->end;

	while (fwd)
	{
		if (!fwd->window && fwd->ideal <= moyenne_a(all))
			return (rotate(all->a, 1));
		if (!rvs->window && rvs->ideal <= moyenne_a(all))
			return (reverse_rotate(all->a, 1));
		fwd = fwd->next;
		rvs = rvs->prev;
	}
	return ;
}

void	to_b(t_all *all)
{
	while (have_not_windowed(all->a))
	{
		if ((all->a->nb_element == 3 && \
			all->a->start->ideal >= all->a->start->next->ideal + 1))
		{
			swap(all->a, 1);
			get_window(all->a);
		}
		if (!all->a->start->window && all->a->start->ideal <= moyenne_a(all))
			push(all->a, all->b, 1);
		else if (all->a->start && all->a->start->next && (all->a->start == all->a->start->next + 1))
			swap(all->a, 1);
		else
			rotate_to_nearest(all);
		if (all->b->start && all->b->start->next && (all->b->start + 1 == all->b->start->next))
			swap(all->b, 1);
	}
}
