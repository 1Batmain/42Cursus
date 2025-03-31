/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:45:04 by bduval            #+#    #+#             */
/*   Updated: 2025/03/31 16:44:19 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_rotate_b(t_all *all)
{
	while (all->e->b != all->b->end)
	{	
		all->e->b_mem = all->e->b;
		all->e->b_rev_mem = all->e->b_rev;
		all->e->a = all->a->start;
		all->e->a_rev = all->a->end;
		all->e->moment = get_nearest_rotation_value_to_a(all);
		if (all->e->moment && \
			(all->e->moment + all->e->nb_rotate < all->e->best \
			|| (all->e->moment + all->e->nb_rotate == all->e->best && \
				all->e->b_mem->ideal > all->e->b_best->ideal)))
		{
			all->e->best = all->e->moment + all->e->nb_rotate;
			all->e->best_moment = all->e->moment;
			all->e->b_best = all->e->b_mem;
		}
		all->e->b = all->e->b_mem->next;
		if (all->e->b)
			all->e->b_rev = all->e->b->prev;
		all->e->nb_rotate++;
		if (all->e->nb_rotate > all->e->best)
			break ;
	}
}

static void	set_new_best(t_all *all)
{
	all->e->best = all->e->moment + all->e->nb_rotate;
	all->e->best_moment = all->e->moment;
	all->e->b_best = all->e->b_rev_mem;
	all->e->rev = 1;
}

void	check_rev_rotate_b(t_all *all)
{
	all->e->nb_rotate = 0;
	all->e->b = all->b->start;
	all->e->b_rev = all->b->end;
	while (all->e->b_rev != all->b->start)
	{	
		all->e->b_mem = all->e->b;
		all->e->b_rev_mem = all->e->b_rev;
		all->e->a = all->a->start;
		all->e->a_rev = all->a->end;
		all->e->moment = get_nearest_rotation_value_to_a(all);
		if (all->e->moment && \
			(all->e->moment + all->e->nb_rotate < all->e->best || \
			(all->e->moment + all->e->nb_rotate == all->e->best && \
			all->e->b_rev_mem->ideal > all->e->b_best->ideal)))
			set_new_best(all);
		all->e->b_rev = all->e->b_rev_mem->prev;
		if (all->e->b_rev)
			all->e->b = all->e->b_rev->next;
		all->e->nb_rotate++;
		if (all->e->nb_rotate > all->e->best)
			break ;
	}
}
