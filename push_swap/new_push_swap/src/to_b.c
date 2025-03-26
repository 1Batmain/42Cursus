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
	return (moyenne);
}

void	to_b(t_all *all)
{
	while (have_not_windowed(all->a))
	{
		if (!all->a->start->window && all->a->start->ideal <= moyenne_a(all))
			push(all->a, all->b, 1);
	//	else if (is_swapable(all->a))
	//		swap(all->a, 1);
		else
			rotate(all->a, 1);
	}
}
