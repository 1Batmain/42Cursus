/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:02:35 by bduval            #+#    #+#             */
/*   Updated: 2025/03/19 15:28:21 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	double_rotate(t_stack *l1, t_stack *l2, int print)
{
	(*l1->nb_op)--;
	rotate(l1, 0);
	rotate(l2, 0);
	if (print)
		ft_printf("rr\n");
}

void	double_reverse_rotate(t_stack *l1, t_stack *l2, int print)
{
	(*l1->nb_op)--;
	reverse_rotate(l1, 0);
	reverse_rotate(l2, 0);
	if (print)
		ft_printf("rrr\n");
}
