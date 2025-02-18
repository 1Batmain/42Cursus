/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:36:47 by bduval            #+#    #+#             */
/*   Updated: 2025/02/18 09:07:29 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	get_nearest_rotation_value_to_b(t_all *all)
{
	int	i;

	i = 0;
	while (i++ < (ft_max(all->a->nb_element, all->b->nb_element)))
	{
		if (is_pushable_to_b2(all->e->a, all->e->b, all->b))
			return (i);
		if (is_pushable_to_b2(all->e->a_rev, all->e->b_rev, all->b))
			return (i);
		if (is_pushable_to_b(all->e->a, all->b))
			return (i);
		if (is_pushable_to_b(all->e->a_rev, all->b))
			return (i);
		if (is_pushable_to_b2(all->a->start, all->e->b, all->b))
			return (i);
		if (is_pushable_to_b2(all->a->start, all->e->b_rev, all->b))
			return (i);
		update_voltigeur(all);
	}
	return (0);
}

int	do_nearest_rotation_to_b(t_all *all)
{
	int	i;

	i = 0;
	while (i++ < (ft_max(all->a->nb_element, all->b->nb_element)))
	{
		if (is_pushable_to_b2(all->e->a, all->e->b, all->b))
			return (double_rotate(all->a, all->b), i);
		if (is_pushable_to_b2(all->e->a_rev, all->e->b_rev, all->b))
			return (double_reverse_rotate(all->a, all->b), i);
		if (is_pushable_to_b(all->e->a, all->b))
			return (rotate(all->a, 1), i);
		if (is_pushable_to_b(all->e->a_rev, all->b))
			return (reverse_rotate(all->a, 1), i);
		if (is_pushable_to_b2(all->e->a_best, all->e->b, all->b))
			return (rotate(all->b, 1), i);
		if (is_pushable_to_b2(all->e->a_best, all->e->b_rev, all->b))
			return (reverse_rotate(all->b, 1), i);
		update_voltigeur(all);
	}
	return (0);
}

void	apply_best_move_to_b(t_all *all)
{
	if (all->e->rev)
		while (all->a->end != all->e->a_best)
			reverse_rotate(all->a, 1);
	else
		while (all->a->start != all->e->a_best)
			rotate(all->a, 1);
	init_voltigeur(all);
	while (!is_pushable_to_b(all->a->start, all->b) && all->e->best_moment--)
		do_nearest_rotation_to_b(all);
}

void	to_b_sorted(t_all *all)
{
	while (have_not_windowed(all->a))
	{
		if (all->a->start->ideal == all->a->start->next->ideal + 1)
		{
			swap(all->a);
			get_window(all->a);
		}
		if (is_pushable_to_b(all->a->start, all->b))
			push(all->a, all->b);
		else
		{
			init_voltigeur(all);
			check_rotate_a(all);
			check_rev_rotate_a(all);
			apply_best_move_to_b(all);
		}
			get_window(all->a);
	}
}
