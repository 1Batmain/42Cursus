#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "ft_printf.h"
#include "push_swap.h"

# define INTERACTIVE	1
struct s_element
{
	int	value;
	int	ideal;
	int	*min;
	int	*max;
	int	*nb_element;
	struct s_element	*next;
	struct s_element	*prev;
};
typedef struct	s_element	t_element;

typedef	struct	s_stack
{
	t_element	*start;
	t_element	*end;
	t_element	*moment;
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
	t_element *l1;
	t_element *temp;
	
	l1 = l->start;
	if (!l1 || !l1->next)
		return ;
	temp = (l1)->next;
	temp->prev = NULL;
	l1->next = l1->next->next;
	l1->prev = temp;
	temp->next = l1;
	l1 = temp;
	ft_printf("s\n");
	return ;
}

void	push(t_stack *a, t_stack *b)
{
	t_element	*temp;
	t_element	*l1;
	t_element	*l2;
	
	l1 = a->start;
	l2 = b->start;
	if (!l1)
		return ;
	temp = l2;
	l2 = l1;
	l1 = l1->next;
	if (l1)
	{
		l1->prev = NULL;
		a->nb_element--;
	}
	l2->next = temp;
	l2->prev = NULL;
	b->nb_element++;
	if (temp)
		temp->prev = l2;
	ft_printf("p\n");
	return ;
}

void	rotate(t_stack *l)
{
	t_element	*l1;
	t_element	*temp;
	t_element	*indice;

	l1 = l->start;
	if (!l1 || !l1->next)
		return ;
	temp = l1->next;
	temp->prev = NULL;
	indice = l1;
	while (indice->next)
		indice = indice->next;
	indice->next = l1;
	l1->prev = indice;
	l1->next = NULL;
	l1 = temp;
	ft_printf("r\n");
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
	l1 = indice;
	ft_printf("rr\n");
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
			ft_printf("%d(%+d)", l1->value, l1->ideal);
			l1 = l1->next;
		}
		ft_printf("\t\t");
		if (l2)
		{
			ft_printf("%d(%+d)", l2->value, l2->ideal);
			l2 = l2->next;
		}
		ft_printf("\n");
	}
	ft_printf(	"--------\n"\
				"a(%d)\t\tb(%d)\n", nb_elem1, nb_elem2);
}

int	get_min(t_element *l)
{
	int	min;

	min = l->value;
	while (l)
	{
		if (min > l->value)
			min = l->value;
		l = l->next;
	}
	return (min);
}
void	analyse(t_stack *l1)
{
	t_element *outfielder;
	t_element *instant;
	int	pos;
	int	max;

	instant = l1->start;
	pos = 1;
	max = instant->value;
	while (instant)
	{
		instant->ideal = pos++;
		if (instant->value < max)
		{
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
		else
			max = instant->value;
		instant = instant->next;
	}
}

void	sort_stack(t_stack *l1, t_stack *l2)
{
	analyse(l1);
	if (l2)
		return ;
	return ;	
}

int	main(int ac, char **av)
{
	t_stack	l1;
	t_stack	l2;

	l1.start = NULL;
	l2.start = NULL;
	l1.end = NULL;
	l2.end = NULL;
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
