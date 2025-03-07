#include "push_swap.h"

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
void	apply_operation(char *line, t_all *all)
{
	if (strcmp(line, "sa\n"))
		return (swap(all->a));
	if (strcmp(line, "sb\n"))
		return (swap(all->a));
	if (strcmp(line, "pa\n"))
		return (push(all->a));
	if (strcmp(line, "pb\n"))
		return (push(all->b));
	if (strcmp(line, "ra\n"))
		return (rotate(all->a));
	if (strcmp(line, "rb\n"))
		return (rotate(all->b));
	if (strcmp(line, "rr\n"))
		return (double_rotate(all));
	if (strcmp(line, "rrr\n"))
		return (double_reverse_rotate(all));
}
int	is_sorted(t_stack *s)
{
	t_element *e;

	e = s->start;
	while (e)
	{
		if (e->next && e->ideal > e->next->ideal)
			return (0);
		e = e->next;
	}
	return (1);
}

void	check_stack(t_all *all)
{
	char *line;

	line = 1;
	while (*line)
	{
		line = get_next_line(0);
		apply_operation(line, all);
		free(line);
	}
	if (is_sorted(all->a))
		return (ft_printf("Correctly sorted !\n%d operations\n", all->nb_op));
	else
		return (ft_printf("The stack is not sort !\n"));
}

int	main(int ac, char **av)
{
	t_all	all;

	init_stack(&all);
	if (ac <= 1)
		return (1);
	if (get_lst(all.a, ac, av))
		return (ft_printf("Erreur Parsing List\n"), 1);
	all.nb_element = all.a->nb_element;
	check_stack(&all);
	free_elements(&all);
	return (0);
}
