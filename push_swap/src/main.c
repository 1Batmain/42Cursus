/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:54:39 by bduval            #+#    #+#             */
/*   Updated: 2025/02/18 12:09:11 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	print_results(t_all *all)
{
	int nb_elem1;
	int nb_elem2;
	t_element *l1;
	t_element *l2;

	nb_elem1 = 0;
	nb_elem2 = 0;
	l1 = all->a->start;
	l2 = all->b->start;
	if (l1)
		nb_elem1 = all->a->nb_element;
	if (l2)
		nb_elem2 = all->b->nb_element;
	while (l1 || l2)
	{
		if (l1)
		{
			ft_printf("%d(%+d)(%d)", l1->value, l1->ideal, l1->window);
			l1 = l1->next;
		}
		ft_printf("\t\t");
		if (l2)
		{
			ft_printf("%d(%+d)(%d)", l2->value, l2->ideal, l2->window);
			l2 = l2->next;
		}
		ft_printf("\n");
	}
	ft_printf(	"--------\n"\
				"a(%d)\t\tb(%d)\n"\
				"min :\n"\
				"%d\t\t%d\nmax :\n%d\t\t%d\n"\
				, nb_elem1, nb_elem2, all->a->min, all->b->min, all->a->max, all->b->max);
	ft_printf("NB_OP : %d\n", all->nb_op);
}

void	to_the_top(t_all *all)
{
	if (all->a->start->ideal > all->a->nb_element / 2)
		while (all->a->start->ideal != 1)
			rotate(all->a, 1);
	else
		while (all->a->start->ideal != 1)
			reverse_rotate(all->a, 1);
}

void	sort_stack(t_all *all)
{
	analyse(all->a);
	to_b_sorted(all);
	back_to_a(all);
	to_the_top(all);
	//print_results(all);
	return ;
}

void	free_elements(t_all *all)
{
	t_element	*e;
	t_element	*tmp;

	e = all->a->start;
	while (e)
	{
		tmp = e;
		e = e->next;
		free(tmp);
	}
}

int	main(int ac, char **av)
{
	t_all	all;

	init_stack(&all);
	if (ac <= 1)
		return (1);
	if (get_lst(all.a, ac, av))
		return (ft_printf("Erreur Parsing List\n"), 1);
	sort_stack(&all);
	free_elements(&all);
	return (0);
}
/*
# define INTERACTIVE	0


int	main(int ac, char **av)
{
	t_all	all;

	init_stack(&all);
	if (ac <= 1)
		return (1);
	if (get_lst(all.a, ac, av))
		return (ft_printf("Erreur Parsing List\n"), 1);

	char	cmd[4];
	if (INTERACTIVE)
	{
		sort_stack(&all);
		print_results(&all);
		while (1)
		{
			ft_printf("Command : ");
			scanf("%s", cmd);
			if (!ft_strcmp(cmd, "sa"))
				swap(all.a);
			if (!ft_strcmp(cmd, "sb"))
				swap(all.b);
			if (!ft_strcmp(cmd, "ss"))
			{
				swap(all.a);
				swap(all.b);
			}
			if (!ft_strcmp(cmd, "pa"))
				push(all.b, all.a);
			if (!ft_strcmp(cmd, "pb"))
				push(all.a, all.b);
			if (!ft_strcmp(cmd, "ra"))
				rotate(all.a);
			if (!ft_strcmp(cmd, "rb"))
				rotate(all.b);
			if (!ft_strcmp(cmd, "rr"))
			{
				rotate(all.a);
				rotate(all.b);
			}
			if (!ft_strcmp(cmd, "rra"))
				reverse_rotate(all.a);
			if (!ft_strcmp(cmd, "rrb"))
				reverse_rotate(all.b);
			if (!ft_strcmp(cmd, "rrr"))
			{
				reverse_rotate(all.a);
				reverse_rotate(all.b);
			}
			print_results(&all);
		}
	}
	else 
		sort_stack(&all);
	//print_results(&all);
	return (0);
}

 */
