/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:33:11 by bduval            #+#    #+#             */
/*   Updated: 2025/03/20 15:57:22 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	ft_max(int a, int b)
{
	if (b > a)
		return (b);
	return (a);
}

int	is_space(char c)
{
	if (c == ' ' || (c >= 7 && c <= 13))
		return (1);
	return (0);
}

int	is_sign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

int	is_doublon(t_stack *l, t_element *new)
{
	t_element	*e;

	e = l->start;
	while (e)
	{
		if (e->value == new->value)
			return (free(new), 1);
		e = e->next;
	}
	return (0);
}
