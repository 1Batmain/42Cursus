#include "push_swap.h"

# define INTERACTIVE	0

void	print_results(t_stack *a, t_stack *b)
{
	int nb_elem1;
	int nb_elem2;
	t_element *l1;
	t_element *l2;

	nb_elem1 = 0;
	nb_elem2 = 0;
	l1 = a->start;
	l2 = b->start;
	if (l1)
		nb_elem1 = a->nb_element;
	if (l2)
		nb_elem2 = b->nb_element;
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
				, nb_elem1, nb_elem2, a->min, b->min, a->max, b->max);
	ft_printf("NB_OP : %d\n", *a->nb_op);
}

int	main(int ac, char **av)
{
	t_stack	l1;
	t_stack	l2;
	int	nb_op;

	nb_op = 0;
	init_stack(&l1, &l2, &nb_op);
	if (ac <= 1)
		return (1);
	if (get_lst(&l1, ac, av))
		return (ft_printf("Erreur Parsing List\n"), 1);

	char	cmd[4];
	if (INTERACTIVE)
	{
		sort_stack(&l1, &l2);
		print_results(&l1, &l2);
		while (1)
		{
			ft_printf("Command : ");
			scanf("%s", cmd);
			if (!ft_strcmp(cmd, "sa"))
				swap(&l1);
			if (!ft_strcmp(cmd, "sb"))
				swap(&l2);
			if (!ft_strcmp(cmd, "ss"))
			{
				swap(&l1);
				swap(&l2);
			}
			if (!ft_strcmp(cmd, "pa"))
				push(&l2, &l1);
			if (!ft_strcmp(cmd, "pb"))
				push(&l1, &l2);
			if (!ft_strcmp(cmd, "ra"))
				rotate(&l1);
			if (!ft_strcmp(cmd, "rb"))
				rotate(&l2);
			if (!ft_strcmp(cmd, "rr"))
			{
				rotate(&l1);
				rotate(&l2);
			}
			if (!ft_strcmp(cmd, "rra"))
				reverse_rotate(&l1);
			if (!ft_strcmp(cmd, "rrb"))
				reverse_rotate(&l2);
			if (!ft_strcmp(cmd, "rrr"))
			{
				reverse_rotate(&l1);
				reverse_rotate(&l2);
			}
			print_results(&l1, &l2);
		}
	}
	else 
		sort_stack(&l1, &l2);
	//print_results(&l1, &l2);
	return (0);
}

/*
 */
