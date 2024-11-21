# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bduval <bduval@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 13:54:02 by bduval            #+#    #+#              #
#    Updated: 2024/11/21 17:22:13 by bduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS 	= -Wall -Werror -Wextra -D BUFFER_SIZE=42
NAME 	= get_next_line

SRC_DIR = ./
LIB_DIR	= -I ./
OBJ_DIR	= ./

MANDATORY = get_next_line get_next_line_utils
MANDATORY_BONUS =

SRC = $(MANDATORY:%=%.c)
OBJ = $(SRC:%.c=$(OBJ_DIR)%.o)

SRC_BONUS = $(MANDATORY_BONUS:%=%.c)
OBJ_BONUS = $(SRC_BONUS:%.c=$(OBJ_DIR)%.o)

TEST_MAIN = test/main.c


all : $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)	
	$(CC) $(LIB_DIR) $^ -o $@

objdir :
	mkdir -p obj
bonus : $(OBJ) $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ) $(OBJ_BONUS)

re	: fclean all
	
clean :
	rm -rf $(OBJ) $(OBJ_BONUS)


fclean : clean 
	rm -f $(NAME) a.out

test : $(TEST_FILE) $(TEST_MAIN)
	$(CC) $(CFLAGS) $(LIB_DIR) -g $(SRC) $(TEST_MAIN)

.PHONY : re clean fclean test
