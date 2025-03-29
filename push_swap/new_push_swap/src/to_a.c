/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:40:57 by bduval            #+#    #+#             */
/*   Updated: 2025/03/27 00:21:01 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	get_nearest_rotation_value_to_a(t_all *all)
{
	int	i;

	i = 1;
	while (i < (ft_max(all->b->nb_element, all->a->nb_element)))
	{
		if (is_pushable_to_a2(all->e->b, all->e->a, all))
			return (i);
		if (is_pushable_to_a2(all->e->b_rev, all->e->a_rev, all))
			return (i);
		if (is_pushable_to_a(all->e->b, all))
			return (i);
		if (is_pushable_to_a(all->e->b_rev, all))
			return (i);
		if (is_pushable_to_a2(all->e->b_mem, all->e->a, all))
			return (i);
		if (is_pushable_to_a2(all->e->b_mem, all->e->a_rev, all))
			return (i);
		update_voltigeur(all);
		i++;
	}
	return (0);
}

int	do_nearest_rotation_to_a(t_all *all)
{
	int	i;

	i = 1;
	while (i < (ft_max(all->b->nb_element, all->a->nb_element)))
	{
		if (is_pushable_to_a2(all->e->b, all->e->a, all))
			return (double_rotate(all->b, all->a, 1), i);
		if (is_pushable_to_a2(all->e->b_rev, all->e->a_rev, all))
			return (double_reverse_rotate(all->b, all->a, 1), i);
		if (is_pushable_to_a(all->e->b, all))
			return (rotate(all->b, 1), i);
		if (is_pushable_to_a(all->e->b_rev, all))
			return (reverse_rotate(all->b, 1), i);
		if (is_pushable_to_a2(all->b->start, all->e->a, all))
			return (rotate(all->a, 1), i);
		if (is_pushable_to_a2(all->b->start, all->e->a_rev, all))
			return (reverse_rotate(all->a, 1), i);
		update_voltigeur(all);
		i++;
	}
	return (0);
}

void	apply_best_move_to_a(t_all *all)
{
	if (all->e->rev)
		while (all->b->end != all->e->b_best)
			reverse_rotate(all->b, 1);
	else
		while (all->b->start != all->e->b_best)
			rotate(all->b, 1);
	all->e->b = all->b->start;
	all->e->b_rev = all->b->end;
	all->e->a = all->a->start;
	all->e->a_rev = all->a->end;
	while (!is_pushable_to_a(all->b->start, all) && all->e->best_moment--)
		do_nearest_rotation_to_a(all);
}

void	back_to_a(t_all *all)
{
	while (all->b->nb_element)
	{
		if (all->b->start && all->b->start->next && (all->b->start + 1 == all->b->start->next))
			swap(all->b, 1);
		if (is_pushable_to_a(all->b->start, all))
		{
			push(all->b, all->a, 1);
			if (!all->b->nb_element)
				return ;
		}
		if (!is_pushable_to_a(all->b->start, all))
		{
			init_voltigeur(all);
			check_rotate_b(all);
			check_rev_rotate_b(all);
			apply_best_move_to_a(all);
		}
	}
}
