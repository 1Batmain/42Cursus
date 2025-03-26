/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:46:47 by bduval            #+#    #+#             */
/*   Updated: 2025/03/26 19:49:08 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	get_chunk_size(t_all *all)
{
	return (1);
	if (all->nb_element < 100)
		return (1);
	else
		return (all->nb_element / 100);
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
	t_element	*front;
	t_element	*rev;

	front = all->b->start;
	rev = all->b->end;
	while (front || rev)
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
		if (front)
			front = front->next;
		if (rev)
			rev = rev->prev;
	}
}
