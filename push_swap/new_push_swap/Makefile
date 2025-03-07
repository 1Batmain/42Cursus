# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bduval <bduval@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 13:54:02 by bduval            #+#    #+#              #
#    Updated: 2025/02/13 14:35:49 by bduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS 	= -Wall -Werror -Wextra -g
NAME 	= push_swap

SRC_DIR 	=	src/
HEADER_DIR	=	-I header/ -I biglibft/header
TEST_DIR	=	src/
OBJ_DIR		=	obj/
BONUS_OBJ_DIR		=	bonus_obj/
LIB_DIR		= biglibft/
LIB			= -L biglibft/ -lft

MANDATORY = main list operations double_operations window max_min to_a to_b \
			check_rotate is_pushable voltigeur utils

SRC = $(MANDATORY:%=$(SRC_DIR)%.c)
OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all : 		$(NAME)

$(NAME):	$(OBJ) $(LIB)
	$(CC) $(OBJ) $(LIB) -o $(NAME)

$(OBJ_DIR)%.o :	$(SRC_DIR)%.c $(OBJ_DIR) $(LIB)
	$(CC) $(CFLAGS) $(HEADER_DIR) -c $< -o $@ -g

$(LIB) :
	cd $(LIB_DIR); make; cd ..;

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

init:
	mkdir -p $(SRC_DIR) $(TEST_DIR) $(HEADER_DIR)

re	: 		fclean all

clean :
	rm -rf $(OBJ_DIR) 

fclean : clean 
	rm -f $(NAME) a.out

.PHONY : re clean fclean test
