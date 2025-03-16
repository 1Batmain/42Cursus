/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:36:47 by bduval            #+#    #+#             */
/*   Updated: 2025/02/18 12:11:13 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	get_nearest_rotation_value_to_b(t_all *all)
{
	int	i;

	i = 0;
	while (i++ < (ft_max(all->a->nb_element, all->b->nb_element)))
	{
		if (is_pushable_to_b2(all->e->a, all->e->b, all))
			return (i);
		if (is_pushable_to_b2(all->e->a_rev, all->e->b_rev, all))
			return (i);
		if (is_pushable_to_b(all->e->a, all))
			return (i);
		if (is_pushable_to_b(all->e->a_rev, all))
			return (i);
		if (is_pushable_to_b2(all->a->start, all->e->b, all))
			return (i);
		if (is_pushable_to_b2(all->a->start, all->e->b_rev, all))
			return (i);
		update_voltigeur(all);
	}
	return (0);
}

int	get_chunk_size(t_all *all)
{
	if (all->nb_element <= 100)
		return (1);
	else if (all->nb_element <= 300)
		return (2);
	else if (all->nb_element <= 500)
		return (3);
	else if (all->nb_element <= 800)
		return (4);
	else if (all->nb_element <= 1200)
		return (5);
	else if (all->nb_element <= 1500)
		return (6);
	else if (all->nb_element <= 1800)
		return (6);
	return (8);
}

void	to_b_sorted(t_all *all)
{
	int			chunk;
	int			starter;
	int			chunk_size;
	t_element	*e;

	chunk_size = get_chunk_size(all);
	all->curr_chunk = 0;
	all->nb_chunk = chunk_size;
	chunk = all->nb_element / chunk_size;
	e = NULL;
	while (have_not_windowed(all->a))
	{
		if (all->curr_chunk < all->nb_chunk)
			all->curr_chunk++;
		starter = 1;
		while (all->a->start != e || starter)
		{
			if((!e || !e->window) && all->a->start->window)
				e = all->a->start;
			if (!all->a->start->window && (all->a->start->ideal <= chunk * all->curr_chunk || all->curr_chunk == all->nb_chunk))
				push(all->a, all->b);
			else
				rotate(all->a, 1);
			starter = 0;
		}
	}
}

