# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bduval <bduval@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 10:56:02 by bduval            #+#    #+#              #
#    Updated: 2024/11/18 22:01:15 by bduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = cc
CFLAGS 	= -Wall -Werror -Wextra
NAME 	= libft.a

SRC_DIR = ./
LIB_DIR	= -I ./
OBJ_DIR	= ./

MANDATORY = ft_atoibase ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha ft_isascii \
			ft_isdigit ft_isprint ft_isspace ft_itoa \
			ft_memchr ft_memcmp ft_memcpy \
			ft_memmove ft_memset ft_putchar_fd ft_putendl_fd ft_putnbr_fd \
			ft_putstr_fd ft_split ft_strchr ft_strdup ft_striteri ft_strjoin \
			ft_strlcat ft_strlcpy ft_strlen ft_strmapi ft_strncmp ft_strnstr \
			ft_strrchr ft_strtrim ft_substr ft_tolower ft_toupper 

MANDATORY_BONUS = ft_lstadd_back ft_lstmap ft_lstnew ft_lstsize \
				  ft_lstadd_front ft_lstclear ft_lstdelone ft_lstiter ft_lstlast

SRC = $(MANDATORY:%=%.c)
OBJ = $(SRC:%.c=%.o)
SRC_BONUS = $(MANDATORY_BONUS:%=%.c)
OBJ_BONUS = $(SRC_BONUS:%.c=%.o)
TEST_MAIN = ../test/main.c


all : $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) -c $(LIB_DIR) $< -o $@

$(NAME) : $(OBJ)
	ar rcs $@ $(OBJ)

bonus : $(OBJ) $(OBJ_BONUS)
	ar rcs $@ $(OBJ) $(OBJ_BONUS)

re	: fclean all
	
clean :
	rm -rf $(OBJ)

fclean : clean 
	rm -f $(NAME) a.out


test : $(TEST_FILE) $(TEST_MAIN)
	$(CC) $(CFLAGS) $(LIB_DIR) -g $(SRC) $(TEST_MAIN)

.PHONY : re clean fclean test
