#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "ft_printf.h"
#include "push_swap.h"

# define INTERACTIVE	0
struct s_element
{
	int	value;
	int	ideal;
	int	window;
	struct s_element	*next;
	struct s_element	*prev;
};
typedef struct	s_element	t_element;

typedef	struct	s_stack
{
	t_element	*start;
	t_element	*end;
	int	nb_element;
	int	min;
	int	max;
}	t_stack;

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
	if (start)
		start->prev = new;
	list->start = new;
	temp = list->start;
	while (temp->next)
		temp = temp->next;
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
		return (list->start = new, 0);
	temp = start;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
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

void	swap(t_stack *l)
{
	t_element *temp;
	
	if (!l->start || !l->start->next)
		return ;
	temp = (l->start)->next;
	temp->prev = NULL;
	l->start->next = l->start->next->next;
	l->start->prev = temp;
	temp->next = l->start;
	l->start = temp;
	ft_printf("s\n");
	return ;
}
void	get_new_max(t_stack *a)
{
	t_element *i;

	a->max = a->max - 1;
	while (1)
	{
		i = a->start;
		while (i)
		{
			if (i->ideal == a->max)
				return ;
			i = i->next;
		}
		a->max--;
	}
}

void	get_new_min(t_stack *a)
{
	t_element *i;

	a->min = a->min + 1;
	while (1)
	{
		i = a->start;
		while (i)
		{
			if (i->ideal == a->min)
				return ;
			i = i->next;
		}
		a->min++;
	}
}

void	update_max_min(t_stack *a, t_stack *b)
{
	if (a->start->ideal == a->max)
	{
		if (b->max < a->start->ideal - 1)
			a->max--;
		else if (a->nb_element > 1)
			get_new_max(a);
	}
	if (a->start->ideal == a->min)
	{
		if (b->min > a->start->ideal + 1)
			a->min++;
		else if (a->nb_element > 1)
			get_new_min(a);
	}
	if (a->start->ideal > b->max)
		b->max = a->start->ideal;
	if (a->start->ideal < b->min)
		b->min = a->start->ideal;
	if (a->nb_element == 1)
	{
		a->min = 2147483647;
		a->max = -2147483648;
	}
}

void	push(t_stack *a, t_stack *b)
{
	t_element	*temp;

	if (!a->start)
		return ;
	update_max_min(a, b);
	temp = b->start;
	b->start = a->start;
	a->start = a->start->next;
	if (a->start)
	{
		a->start->prev = NULL;
		a->nb_element--;
	}
	else
		a->nb_element = 0;
	b->start->next = temp;
	b->start->prev = NULL;
	b->nb_element++;
	if (temp)
		temp->prev = b->start;
	return ;
}

void	rotate(t_stack *l)
{
	t_element	*temp;
	t_element	*indice;

	if (!l->start || !l->start->next)
		return ;
	temp = l->start->next;
	temp->prev = NULL;
	indice = l->start;
	while (indice->next)
		indice = indice->next;
	indice->next = l->start;
	l->start->prev = indice;
	l->start->next = NULL;
	l->start = temp;
	return ;
}

void	reverse_rotate(t_stack *l)
{
	t_element 	*l1;
	t_element 	*indice;

	l1 = l->start;
	if (!l1 || !l1->next)
		return ;
	indice = l1;
	while (indice->next)
		indice = indice->next;
	indice->next = l1;
	indice->prev->next = NULL;
	indice->prev = NULL;
	l1->prev = indice;
	l->start = indice;
	return ;
}

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
}

void	back_propagate(t_element *instant)
{
	t_element *outfielder;

	outfielder = instant->prev;
	while (outfielder)
	{
		if (instant->value <= outfielder->value)
		{
			if (instant->ideal > outfielder->ideal)
				instant->ideal = outfielder->ideal;
			outfielder->ideal++;
		}
		outfielder  = outfielder->prev;
	}
}

void	get_window(t_stack *l1)
{
	t_element	*i;
	t_element	*start;
	t_element	*best;
	int			count;
	int			max;

	i = l1->start;
	max = 0;
	while (i)
	{

		start = i;
		count = 1;
		while (i->next && i->next->ideal >= i->ideal)
		{
			count++;
			i = i->next;
			if (!i->next && l1->start->ideal >= i->ideal)
			{
				i = l1->start;
				count++;
			}
		}
		if (count > max)
		{
			best = start;
			max = count;
		}
		i = start->next;
	}
	count = 0;
	while (count < max)
	{
		best->window = 1;
		if (best->next)
			best = best->next;
		else
			best = l1->start;
		count++;
	}
}

void	analyse(t_stack *l1)
{
	t_element *instant;
	int	pos;
	int	max;

	pos = 1;
	instant = l1->start;
	max = instant->value;
	while (instant)
	{
		instant->ideal = pos++;
		if (instant->value < max)
			back_propagate(instant);
		else
			max = instant->value;
		instant = instant->next;
	}
	l1->min = 1;
	l1->max = --pos;
	get_window(l1);
}

void	sort_stack(t_stack *l1, t_stack *l2)
{
	int	on;
	t_element	*i;

	analyse(l1);
	on = 42;
	while (on)
	{
		i = l1->start;
		if (!i->window)
		{
			push(l1, l2);
		}
		else
			rotate(l1);
		on--;
	}
	return ;	
}


void	init_stack(t_stack *l1, t_stack *l2)
{
	l1->start = NULL;
	l2->start = NULL;
	l1->end = NULL;
	l2->end = NULL;
	l1->max = -2147483648;
	l2->max = -2147483648;
	l1->min = 2147483647;
	l2->min = 2147483647;
	l1->nb_element = 0;
	l2->nb_element = 0;
}

int	main(int ac, char **av)
{
	t_stack	l1;
	t_stack	l2;

	init_stack(&l1, &l2);
	if (ac <= 1)
		return (1);
	if (get_lst(&l1, ac, av))
		return (ft_printf("Erreur Parsing List\n"), 1);
	
	char	cmd[4];
	if (INTERACTIVE)
	{
		int nb_op = 1;
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
			ft_printf("%d Operations\n", nb_op++);
		}
	}
	else 
		sort_stack(&l1, &l2);
	print_results(&l1, &l2);
	return (0);
}

/*
 */
