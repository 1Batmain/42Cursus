/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:26:55 by bduval            #+#    #+#             */
/*   Updated: 2025/03/20 16:26:43 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_all *all)
{
	t_element	*e;

	if (all->b->nb_element != 0)
		return (0);
	e = all->a->start;
	while (e)
	{
		if (e->next && e->value > e->next->value)
			return (0);
		e = e->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	*line;
	t_all	all;

	if (ac > 1)
	{
		init_stack(&all);
		if (get_lst(all.a, ac, av))
			return (ft_printf("Error\n"));
		all.nb_element = all.a->nb_element;
		line = (char *)1;
		while (line)
		{
			line = get_next_line(0);
			do_operation(line, &all);
			free(line);
		}
		if (is_sorted(&all))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	else
		return (ft_printf("You should provide a list of numbers to sort\n"));
}
