# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bduval <bduval@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 13:54:02 by bduval            #+#    #+#              #
#    Updated: 2024/11/25 18:48:38 by bduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS 	= -Wall -Werror -Wextra
NAME 	= libftprintf.a

SRC_DIR 	=	./srcs/
HEADER_DIR	=	-I ./includes
OBJ_DIR		=	./obj/
LIB			=

MANDATORY = ft_printf  ft_atoi
MANDATORY_BONUS =

SRC = $(MANDATORY:%=$(SRC_DIR)%.c)
OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

SRC_BONUS = $(MANDATORY_BONUS:%=%.c)
OBJ_BONUS = $(SRC_BONUS:%.c=$(OBJ_DIR)%.o)

TEST_MAIN = test/main2.c

all : $(NAME)

$(OBJ_DIR)%.o :$(SRC_DIR)%.c $(OBJ_DIR)
	$(CC) $(CFLAGS) $(HEADER_DIR) -c $< -o $@ -g

$(NAME) : $(OBJ)	
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR) :
	mkdir -p obj

bonus : $(OBJ) $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ) $(OBJ_BONUS)

re	: fclean all
	
clean :
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean : clean 
	rm -f $(NAME) a.out

test : $(TEST_FILE) $(TEST_MAIN) $(OBJ)
	$(CC) $(CFLAGS) $(HEADER_DIR) -g $(OBJ) $(TEST_MAIN)

.PHONY : re clean fclean test
