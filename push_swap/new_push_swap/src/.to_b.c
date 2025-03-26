/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:36:47 by bduval            #+#    #+#             */
/*   Updated: 2025/03/26 15:45:41 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	is_pushable_to_chunk_1(int chunk, t_element *e)
{
	if (!e->window && \
		(e->ideal <= chunk * 1 && (e->ideal > 0)))
		return (1);
	return (0);
}

int	is_pushable_to_chunk(int chunk, t_element *e, t_all *all)
{
	if (!e->window && \
		((e->ideal <= chunk * all->curr_chunk && (e->ideal > chunk * (all->curr_chunk - 1)))|| \
		all->curr_chunk == all->nb_chunk))
		return (1);
	return (0);
}

int	is_pushable_to_next_chunk(int chunk, t_element *e, t_all *all)
{
	if (!e->window && \
		((e->ideal <= chunk * (all->curr_chunk + 1) && \
		  (e->ideal > chunk * (all->curr_chunk)))|| \
		all->curr_chunk + 1 == all->nb_chunk))
		return (1);
	return (0);
}

void	go_to_top(int chunk, t_all *all)
{
	while (!is_pushable_to_chunk_1(chunk, all->b->end))
	{
		reverse_rotate(all->b, 1);
		if (is_pushable_to_next_chunk(chunk, all->a->start, all))
			push(all->a, all->b, 1);
		if (all->b->start->ideal + 1 == all->b->start->next->ideal)
			swap(all->b, 1);
	}
}

static void	nearest_rotate_to_pushable_window(int chunk, t_all *all)
{
	t_element	*e;
	t_element	*e_rev;

	if (is_pushable_to_chunk(chunk, all->a->start, all))
		return ;
	e = all->a->start->next;
	e_rev = all->a->end;
	while (e != all->a->start)
	{
		if (is_pushable_to_chunk(chunk, e, all))
			return (rotate(all->a, 1));
		if (is_pushable_to_chunk(chunk, e_rev, all))
			return (reverse_rotate(all->a, 1));
		if (e->next)
			e = e->next;
		else
			e = all->a->start;
		if (e_rev->prev)
			e_rev = e_rev->prev;
		else
			e_rev = all->a->end;
	}
}

static void	choose_action(int chunk, t_element **e, t_all *all)
{
	if ((!*e || !(*e)->window) && all->a->start->window)
		*e = all->a->start;
	if ((all->a->nb_element == 3 && \
		all->a->start->ideal >= all->a->start->next->ideal + 1))
		swap(all->a, 1);
	if (is_pushable_to_chunk(chunk, all->a->start, all))
		push(all->a, all->b, 1);
	else if (is_pushable_to_next_chunk(chunk, all->a->start, all))
	{
		push(all->a, all->b, 1);
		rotate(all->b, 1);
	}
	nearest_rotate_to_pushable_window(chunk, all);
	//get_window(all->a);
}

int	contain_chunk_values(int chunk, t_all *all)
{
	t_element	*e;

	e = all->a->start;
	while (e)
	{
		if (is_pushable_to_chunk(chunk, e, all))
			return (1);
		e = e->next;
	}
	return (0);
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
		while (contain_chunk_values(chunk, all))
		{
			choose_action(chunk, &e, all);
			starter = 0;
		}
		go_to_top(chunk, all);
	}
}
