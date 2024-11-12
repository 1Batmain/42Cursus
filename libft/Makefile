# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bduval <bduval@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 10:56:02 by bduval            #+#    #+#              #
#    Updated: 2024/11/12 11:40:50 by bduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = cc
CFLAGS 	= -Wall -Werror -Wextra
NAME 	= libft.a

SRC_DIR = srcs/
LIB_DIR	= -I includes/
OBJ_DIR	= objs/

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
	rm -rf $(OBJ_DIR)

fclean : clean 
	rm -f $(NAME) a.out

test : $(TEST_FILE) $(TEST_MAIN)
	$(CC) $(CFLAGS) $(LIB_DIR) $(SRC) $(TEST_MAIN)

.PHONY : re clean fclean test
