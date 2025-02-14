/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:52:28 by bduval            #+#    #+#             */
/*   Updated: 2025/02/13 16:13:43 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	have_not_windowed(t_stack *a)
{
	t_element	*e;

	e = a->start;
	while (e)
	{
		if (!e->window)
			return (1);
		e = e->next;
	}
	return (0);
}

static void	put_on_stack(t_element **stack, t_element *e)
{
	int	i;

	i = 0;
	while (stack[i] && stack[i]->ideal < e->ideal)
		i++;
	stack[i] = e;
	if (i)
		e->prev_window = stack[i - 1];
	else
		e->prev_window = NULL;
}

static void	mark_window(t_element **stack)
{
	t_element	*e;

	while (*stack)
		stack++;
	e = *--stack;
	while (e)
	{
		e->window = 1;
		e = e->prev_window;
	}
}

void	init_window(t_stack *l)
{
	t_element	*e;

	e = l->start;
	while (e)
	{
		e->window = 0;
		e->prev_window = NULL;
		e = e->next;
	}
}

void	get_window(t_stack *l)
{
	t_element	*stack[500];
	t_element	*i;
	int			on;

	ft_bzero(stack, 500 * sizeof(t_element *));
	init_window(l);
	on = 1;
	i = l->start;
	while (i->ideal != 1)
		i = i->next;
	while (on || i->ideal != 1)
	{
		put_on_stack(stack, i);
		i = i->next;
		on = 0;
		if (!i)
			i = l->start;
	}
	mark_window(stack);
}
