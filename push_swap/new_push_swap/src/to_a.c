/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:40:57 by bduval            #+#    #+#             */
/*   Updated: 2025/02/18 09:24:38 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	get_nearest_rotation_value_to_a(t_all *all)
{
	int	i;

	i = 0;
	while (i++ < (ft_max(all->b->nb_element, all->a->nb_element)))
	{
		if (is_pushable_to_a2(all->e->b, all->e->a, all))
			return (i);
		if (is_pushable_to_a2(all->e->b_rev, all->e->a_rev, all))
			return (i);
		if (is_pushable_to_a(all->e->b, all))
			return (i);
		if (is_pushable_to_a(all->e->b_rev, all))
			return (i);
		if (is_pushable_to_a2(all->b->start, all->e->a, all))
			return (i);
		if (is_pushable_to_a2(all->b->start, all->e->a_rev, all))
			return (i);
		update_voltigeur(all);
	}
	return (0);
}

int	do_nearest_rotation_to_a(t_all *all)
{
	int	i;

	i = 0;
	while (i++ < (ft_max(all->b->nb_element, all->a->nb_element)))
	{
		if (is_pushable_to_a2(all->e->b, all->e->a, all))
			return (double_rotate(all->b, all->a), i);
		if (is_pushable_to_a2(all->e->b_rev, all->e->a_rev, all))
			return (double_reverse_rotate(all->b, all->a), i);
		if (is_pushable_to_a(all->e->b, all))
			return (rotate(all->b, 1), i);
		if (is_pushable_to_a(all->e->b_rev, all))
			return (reverse_rotate(all->b, 1), i);
		if (is_pushable_to_a2(all->e->b_best, all->e->a, all))
			return (rotate(all->a, 1), i);
		if (is_pushable_to_a2(all->e->b_best, all->e->a_rev, all))
			return (reverse_rotate(all->a, 1), i);
		update_voltigeur(all);
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

int	chunk_is_done(t_all *all)
{
	int			max_value;
	t_element	*e;

	max_value = (all->nb_element / all->nb_chunk) * (all->curr_chunk - 1);
	e = all->b->start;
	while (e)
	{
		if (e->ideal > max_value)
			return (0);
		e = e->next;
	}
	return (1);
}

void	go_to_current_chunk(t_all *all)
{
	t_element *front;
	t_element *rev;

	front = all->b->start;
	rev = all->b->end;
	while(front || rev)
	{
		if (is_within_current_chunk(all, front))
		{
			while (!is_within_current_chunk(all, all->b->start))
				rotate(all->b, 1);
			return ;
		}
		if (is_within_current_chunk(all, rev))
		{
			while (!is_within_current_chunk(all, all->b->start))
				reverse_rotate(all->b, 1);
			return ;
		}
		if(front)
			front = front->next;
		if (rev)
			rev = rev->prev;
	}
}

void	back_to_a(t_all *all)
{
	while (all->b->nb_element)
	{
		if (all->b->nb_element > 2 && all->b->start->next && all->b->start->ideal == all->b->start->next->ideal + 1)
			swap(all->b);
		if (is_pushable_to_a(all->b->start, all))
		{
			push(all->b, all->a);
			if  (!all->b->nb_element)
				return ;
		}
		if (chunk_is_done(all))
			all->curr_chunk--;
		if (!is_within_current_chunk(all, all->b->start))
			go_to_current_chunk(all);
		if (!is_pushable_to_a(all->b->start, all))
		{
			init_voltigeur(all);
			check_rotate_b(all);
			check_rev_rotate_b(all);
			apply_best_move_to_a(all);
		}
	}
}
