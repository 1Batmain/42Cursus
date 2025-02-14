/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   voltigeur.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:48:49 by bduval            #+#    #+#             */
/*   Updated: 2025/02/14 10:40:46 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	update_voltigeur(t_all *all)
{
	if (all->e->a && all->e->a->next)
		all->e->a = all->e->a->next;
	else
		all->e->a = all->a->start;
	if (all->e->a_rev && all->e->a_rev->prev)
		all->e->a_rev = all->e->a_rev->prev;
	else
		all->e->a_rev = all->a->end;
	if (all->e->b && all->e->b->next)
		all->e->b = all->e->b->next;
	else
		all->e->b = all->b->start;
	if (all->e->b_rev && all->e->b_rev->prev)
		all->e->b_rev = all->e->b_rev->prev;
	else
		all->e->b_rev = all->b->end;
}

void	init_voltigeur(t_all *all)
{
	all->e->a_best = all->a->start;
	all->e->b_best = all->b->start;
	all->e->a = all->a->start;
	all->e->a_rev = all->a->end;
	all->e->b = all->b->start;
	all->e->b_rev = all->b->end;
	all->e->best = ft_max(all->a->nb_element, all->b->nb_element);
	all->e->rev = 0;
	all->e->nb_rotate = 0;
	all->e->best_moment = 1;
	all->e->train_target = NULL;
}
