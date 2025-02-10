#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ABS(x)	(x > 0) ? x : (-x)
struct s_element
{
	int	value;
	int	ideal;
	int	window;
	struct s_element	*prev_window;
	struct s_element	*next;
	struct s_element	*prev;
};

typedef struct	s_element	t_element;
typedef	struct	s_stack
{
	t_element	*start;
	t_element	*end;
	char	name;
	int	nb_element;
	int	min;
	int	max;
	int	*nb_op;
}	t_stack;

struct	s_pile
{
	t_element	*element;
	struct s_pile	*next;
	struct s_pile	*prev;
	struct s_pile	*next_pile;
	struct s_pile	*prev_pile;
};
typedef struct	s_pile	t_pile;

// MAIN
void	print_results(t_stack *a, t_stack *b);

// LIST
void	init_stack(t_stack *l1, t_stack *l2, int *nb_op);
t_element	*new_element(t_stack *list, int value);
int	element_addfront(t_stack *list, t_element *new);
int	element_addback(t_stack *list, t_element *new);
int	get_lst(t_stack *l1, int ac, char **av);

// OPERATIIONS
void	swap(t_stack *l);
void	push(t_stack *a, t_stack *b);
void	rotate(t_stack *l);
void	reverse_rotate(t_stack *l);
void	double_reverse_rotate(t_stack *l1, t_stack *l2);
void	double_rotate(t_stack *l1, t_stack *l2);

// WINDOW
void	get_window(t_stack *l);
// BRAIN
void	get_new_max(t_stack *a);
void	get_new_min(t_stack *a);
void	push_max_min(t_stack *a, t_stack *b);
void	to_b_sorted(t_stack *l1, t_stack *l2);
void	back_propagate(t_element *instant);
void	analyse(t_stack *l);
void	back_to_a(t_stack *l1, t_stack *l2);
void	sort_stack(t_stack *l1, t_stack *l2);
// MAX_MIN
void	get_new_max(t_stack *a);
void	get_new_min(t_stack *a);
void	push_max_min(t_stack *a, t_stack *b);
void	back_propagate(t_element *instant);
void	analyse(t_stack *l);
#endif
