/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:58:54 by bduval            #+#    #+#             */
/*   Updated: 2025/03/20 16:26:25 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_str_match(char *order, char *match)
{
	while (*match)
	{
		if (*match != *order)
			return (0);
		match++;
		order++;
	}
	return (1);
}

void	do_rotation(char *order, t_all *all)
{
	if (ft_str_match(order, "ra\n"))
		return (rotate(all->a, 0));
	if (ft_str_match(order, "rb\n"))
		return (rotate(all->b, 0));
	if (ft_str_match(order, "rr\n"))
		return (double_rotate(all->a, all->b, 0));
	if (ft_str_match(order, "rrr\n"))
		return (double_reverse_rotate(all->a, all->b, 0));
	if (ft_str_match(order, "rra\n"))
		return (reverse_rotate(all->a, 0));
	if (ft_str_match(order, "rrb\n"))
		return (reverse_rotate(all->b, 0));
}

void	do_swap(char *order, t_all *all)
{
	if (ft_str_match(order, "sa\n"))
		return (swap(all->a, 0));
	if (ft_str_match(order, "sb\n"))
		return (swap(all->b, 0));
}

void	do_push(char *order, t_all *all)
{
	if (ft_str_match(order, "pb\n"))
		return (push(all->a, all->b, 0));
	if (ft_str_match(order, "pa\n"))
		return (push(all->b, all->a, 0));
}

void	do_operation(char *order, t_all *all)
{
	if (!order || !*order)
		return ;
	if (*order == 'r')
		do_rotation(order, all);
	if (*order == 's')
		do_swap(order, all);
	if (*order == 'p')
		do_push(order, all);
	return ;
}
