/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:31:23 by bduval            #+#    #+#             */
/*   Updated: 2025/02/14 10:37:33 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

struct s_element
{
	int					value;
	int					ideal;
	int					window;
	struct s_element	*prev_window;
	struct s_element	*next;
	struct s_element	*prev;
};

typedef struct s_element	t_element;
typedef struct s_stack
{
	t_element	*start;
	t_element	*end;
	char		name;
	int			nb_element;
	int			min;
	int			max;
	int			*nb_op;
}	t_stack;

typedef struct s_voltigeur
{
	t_element	*a;
	t_element	*a_rev;
	t_element	*b;
	t_element	*b_rev;
	t_element	*a_mem;
	t_element	*b_mem;
	t_element	*a_rev_mem;
	t_element	*b_rev_mem;
	t_element	*a_best;
	t_element	*train_target;
	t_element	*b_best;
	int			best;
	int			best_moment;
	int			moment;
	int			nb_rotate;
	int			rev;
}	t_voltigeur;

typedef struct s_all
{
	t_stack		stack_a;
	t_stack		stack_b;
	t_voltigeur	voltigeur;
	t_stack		*a;
	t_stack		*b;
	t_voltigeur	*e;
	int			nb_op;
}	t_all;

//UTILS
int		ft_abs(int a);
int		ft_max(int a, int b);

//MAX_MIN
void	push_max_min(t_stack *a, t_stack *b);
void	analyse(t_stack *l);

//OPERATION
void	swap(t_stack *l);
void	push(t_stack *a, t_stack *b);
void	rotate(t_stack *l, int print);
void	reverse_rotate(t_stack *l, int print);
void	double_rotate(t_stack *l1, t_stack *l2);
void	double_reverse_rotate(t_stack *l1, t_stack *l2);

//CHECK_ROTATE
void	check_rotate_b(t_all *all);
void	check_rev_rotate_b(t_all *all);
void	check_rotate_a(t_all *all);
void	check_rev_rotate_a(t_all *all);

//IS_PUSHABLE
int		is_pushable_to_b(t_element *e, t_stack *b);
int		is_pushable_to_b2(t_element *e_from, t_element *e_to, t_stack *b);
int		is_pushable_to_a(t_element *e, t_all *all);
int		is_pushable_to_a2(t_element *e_from, t_element *e_to, t_all *all);

//TO_A
int		get_nearest_rotation_value_to_a(t_all *all);
int		do_nearest_rotation_to_a(t_all *all);
void	apply_best_move_to_a(t_all *all);
void	back_to_a(t_all *all);
void	to_a_sorted(t_all *all);

//TO_B
int		get_nearest_rotation_value_to_b(t_all *all);
int		do_nearest_rotation_to_b(t_all *all);
void	apply_best_move_to_b(t_all *all);
void	to_b_sorted(t_all *all);

//VOLTIGEUR
void	update_voltigeur(t_all *all);
void	init_voltigeur(t_all *all);

//WINDOW
int		have_not_windowed(t_stack *a);
void	get_window(t_stack *l);

//LIST
void	init_stack(t_all *all);
int		get_lst(t_stack *l1, int ac, char **av);
#endif
