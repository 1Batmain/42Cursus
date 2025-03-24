/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:36:47 by bduval            #+#    #+#             */
/*   Updated: 2025/03/24 19:29:54 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	choose_action(int chunk, t_element **e, t_all *all)
{
	if ((!*e || !(*e)->window) && all->a->start->window)
		*e = all->a->start;
	if (!all->a->start->window && \
		(all->a->start->ideal <= chunk * all->curr_chunk || \
		all->curr_chunk == all->nb_chunk))
		push(all->a, all->b, 1);
	else
		rotate(all->a, 1);
}

void	to_b(t_all *all)
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
			choose_action(chunk, &e, all);
			starter = 0;
		}
	}
}
