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
	struct s_element	*next;
	struct s_element	*prev;
};
typedef struct s_element	t_element;

t_element	*new_element(int	value)
{
	t_element *element;
	element = (t_element *)malloc(sizeof(t_element));
	if (!element)
		return (NULL);
	element->value = value;
	element->next = NULL;
	element->prev = NULL;
	return (element);
}

int	element_addfront(t_element **start, t_element *new)
{
	t_element	*temp;
	if (!new)
	{
		while ((*start)->next)
		{
			temp = *start;
			*start = (*start)->next;
			free(temp);
		}
		return (1);
	}
	new->next = *start;
	if (*start)
		(*start)->prev = new;
	*start = new;
	temp = *start;
	while (temp->next)
		temp = temp->next;
	return (0);
}

int	element_addback(t_element **start, t_element *new)
{
	t_element	*temp;
	if (!new)
	{
		while ((*start)->next)
		{
			temp = *start;
			*start = (*start)->next;
			free(temp);
		}
		return (1);
	}
	if (!*start)
		return (*start = new, 0);
	temp = *start;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
	return (0);
}

int	get_lst(t_element **l1, int	ac, char **av)
{
	char	*numbers;
	if (ac == 2)
	{
		numbers = av[1];
		while (*numbers)
		{
			while (!ft_isdigit(*numbers) && *numbers != '-' && *numbers != '+')
				numbers++;
			if (element_addback(l1, new_element(ft_atoi(numbers))))
					return (1);	
			while (ft_isdigit(*numbers) || *numbers == '-' || *numbers == '+')
				numbers++;

		}
	}
	else 
		while (--ac > 0)
		{
			if (element_addfront(l1, new_element(ft_atoi(av[ac]))))
					return (1);	
		}
	return (0);
}

void	swap(t_element **l1)
{
	t_element *temp;
	
	if (!*l1 || !(*l1)->next)
		return ;
	temp = (*l1)->next;
	temp->prev = NULL;
	(*l1)->next = (*l1)->next->next;
	(*l1)->prev = temp;
	temp->next = *l1;
	*l1 = temp;
	ft_printf("s\n");
	return ;
}

void	push(t_element **l1, t_element **l2)
{
	t_element	*temp;
	
	if (!*l1)
		return ;
	temp = *l2;
	*l2 = *l1;
	*l1 = (*l1)->next;
	if (*l1)
		(*l1)->prev = NULL;
	(*l2)->next = temp;
	(*l2)->prev = NULL;
	if (temp)
		temp->prev = *l2;
	ft_printf("p\n");
	return ;
}

void	rotate(t_element **l1)
{
	t_element	*temp;
	t_element	*indice;

	if (!*l1 || !(*l1)->next)
		return ;
	temp = (*l1)->next;
	temp->prev = NULL;
	indice = *l1;
	while (indice->next)
		indice = indice->next;
	indice->next = *l1;
	(*l1)->prev = indice;
	(*l1)->next = NULL;
	*l1 = temp;
	ft_printf("r\n");
	return ;
}

void	reverse_rotate(t_element ** l1)
{
	t_element 	*indice;

	if (!*l1 || !(*l1)->next)
		return ;
	indice = *l1;
	while (indice->next)
		indice = indice->next;
	indice->next = *l1;
	indice->prev->next = NULL;
	indice->prev = NULL;
	(*l1)->prev = indice;
	*l1 = indice;
	ft_printf("rr\n");
	return ;
}

void	print_results(t_element *l1, t_element *l2)
{
	while (l1 || l2)
	{
		if (l1)
		{
			ft_printf("%d", l1->value);
			l1 = l1->next;
		}
		ft_printf("\t");
		if (l2)
		{
			ft_printf("%d", l2->value);
			l2 = l2->next;
		}
		ft_printf("\n");
	}
	ft_printf(	"--------\n"\
				"a\tb\n");
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
void	sort_stack(t_element **a, t_element **b)
{
	int	min;

	while (*a)
	{
		min = get_min(*a);
		while ((*a)->value != min)
			rotate(a);
		push(a, b);
	}
	while (*b)
	{
		push(b, a);
	}
}

int	main(int ac, char **av)
{
	t_element *l1;
	t_element *l2;

	l1 = NULL;
	l2 = NULL;
	if (ac <= 1)
		return (1);
	if (get_lst(&l1, ac, av))
		return (ft_printf("Erreur Parsing List\n"), 1);
	
	char	cmd[4];
	if (INTERACTIVE)
	{
		print_results(l1, l2);
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
			print_results(l1, l2);
		}
	}
	else 
		sort_stack(&l1, &l2);
	print_results(l1, l2);
	return (0);
}

/*
 */
