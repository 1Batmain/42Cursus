#include "push_swap.h"

void	init_stack(t_all *all)
{
	all->a = &all->stack_a;
	all->b = &all->stack_b;
	all->a->name = 'a';
	all->b->name = 'b';
	all->a->start = NULL;
	all->b->start = NULL;
	all->a->end = NULL;
	all->b->end = NULL;
	all->a->max = -2147483648;
	all->b->max = -2147483648;
	all->a->min = 2147483647;
	all->b->min = 2147483647;
	all->a->nb_element = 0;
	all->b->nb_element = 0;
	all->a->nb_op = &all->nb_op;
	all->b->nb_op = &all->nb_op;
}

t_element	*new_element(t_stack *list, int value)
{
	t_element *element;
	element = (t_element *)malloc(sizeof(t_element));
	if (!element)
		return (NULL);
	element->value = value;
	element->next = NULL;
	element->prev = NULL;
	element->ideal = 0;
	list->nb_element++;
	return (element);
}

int	element_addfront(t_stack *list, t_element *new)
{
	t_element	*temp;
	t_element	*start;

	start = list->start;
	if (!new)
	{
		while (start->next)
		{
			temp = start;
			start = start->next;
			free(temp);
		}
		return (1);
	}
	new->next = start;
	if (!start)
		return (list->start = new, list->end = new, 0);
	list->start->prev = new;
	list->start = new;
	return (0);
}

int	element_addback(t_stack *list, t_element *new)
{
	t_element	*temp;
	t_element	*start;

	start = list->start;
	if (!new)
	{
		while (start->next)
		{
			temp = start;
			start = start->next;
			free(temp);
		}
		return (1);
	}
	if (!start)
		return (list->start = new, list->end = new, 0);
	new->prev = list->end;
	list->end->next = new;
	list->end = new;
	return (0);
}

int	get_lst(t_stack *l1, int ac, char **av)
{
	char	*numbers;
	if (ac == 2)
	{
		numbers = av[1];
		while (*numbers)
		{
			while (!ft_isdigit(*numbers) && *numbers != '-' && *numbers != '+')
				numbers++;
			if (element_addback(l1, new_element(l1, ft_atoi(numbers))))
					return (1);
			while (ft_isdigit(*numbers) || *numbers == '-' || *numbers == '+')
				numbers++;

		}
	}
	else
		while (--ac > 0)
		{
			if (element_addfront(l1, new_element(l1, ft_atoi(av[ac]))))
					return (1);	
		}
	return (0);
}
