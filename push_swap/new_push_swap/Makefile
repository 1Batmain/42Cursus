# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bduval <bduval@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 13:54:02 by bduval            #+#    #+#              #
#    Updated: 2025/03/31 16:45:41 by bduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= cc
CFLAGS 	= -Wall -Werror -Wextra -MMD -MP
NAME 	= push_swap

SRC_DIR 		= src/
SRC_DIR_BONUS	= src/checker/
HEADER_DIR		= -I header/ -I biglibft/header
OBJ_DIR			= obj/
OBJ_DIR_BONUS	= obj/checker/
BONUS_OBJ_DIR	= bonus_obj/
LIB_DIR			= biglibft/
LIB				= -L biglibft/ -lft

MANDATORY	= main list operations double_operations window max_min to_a to_b \
			check_rotate is_pushable voltigeur utils chunk valid_list

BONUS		= checker/main operations double_operations utils is_pushable list \
			  max_min window valid_list checker/checker_utils

SRC	= $(MANDATORY:%=$(SRC_DIR)%.c)
OBJ	= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

SRC_BONUS	= $(BONUS:%=$(SRC_DIR)%.c)
OBJ_BONUS	= $(SRC_BONUS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

DEP			= $(MANDATORY:$(SRC_DIR)%.c=$(OBJ_DIR)%.d)
DEP_BONUS	= $(BONUS:$(SRC_DIR)%.c=$(OBJ_DIR)%.d)


all : $(OBJ_DIR) .lib $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIB) -o $@

$(OBJ_DIR)%.o :	$(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(HEADER_DIR) -c $< -o $@ -g

-include $(DEP) $(DEP_BONUS)

bonus	: all checker

checker :	$(OBJ_BONUS) .lib
	$(CC) $(OBJ_BONUS) $(LIB) -o $@

.lib :
	@cd $(LIB_DIR); make; cd ..;
	touch .lib;

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR) $(OBJ_DIR_BONUS)

re	: 		fclean all

clean :
	rm -rf $(OBJ_DIR) 

fclean : clean 
	rm -f $(NAME) checker

.PHONY : re clean fclean test
