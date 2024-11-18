# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bduval <bduval@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 10:56:02 by bduval            #+#    #+#              #
#    Updated: 2024/11/16 15:28:21 by bduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = cc
CFLAGS 	= -Wall -Werror -Wextra
NAME 	= libft.a

SRC_DIR = ./
LIB_DIR	= -I ./
OBJ_DIR	= ./

SRC = $(wildcard $(SRC_DIR)*.c)
OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
TEST_MAIN = test/main.c


all : $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c objs
	$(CC) -c $(LIB_DIR) $< -o $@

objs : 
	mkdir -p $@

$(NAME) : $(OBJ)
	ar rcs $@ $(OBJ)

re	: fclean all
	
clean : 
	rm -rf $(OBJ)

fclean : clean 
	rm -f $(NAME) a.out

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)

test : $(TEST_FILE) $(TEST_MAIN)
	$(CC) $(CFLAGS) $(LIB_DIR) -g $(SRC) $(TEST_MAIN)

.PHONY : re clean fclean test
