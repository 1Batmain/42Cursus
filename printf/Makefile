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
NAME 	= get_next_line

SRC_DIR 	=	./srcs/
HEADER_DIR	=	-I ./includes
OBJ_DIR		=	./obj/
LIB			=	libft.a

MANDATORY = ft_printf
MANDATORY_BONUS =

SRC = $(MANDATORY:%=$(SRC_DIR)%.c)
OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

SRC_BONUS = $(MANDATORY_BONUS:%=%.c)
OBJ_BONUS = $(SRC_BONUS:%.c=$(OBJ_DIR)%.o)

TEST_MAIN = test/main.c

all : $(NAME)

$(OBJ_DIR)%.o :$(SRC_DIR)%.c $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

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
