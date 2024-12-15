CC = cc
CFLAGS 	= -Wall -Werror -Wextra
NAME 	= server

SRC_DIR 	=	srcs/
HEADER_DIR	=	-I includes
OBJ_DIR		=	objs/
LIBFT		= lib/libft
PRINTF		= lib/libftprintf

MANDATORY = main

MANDATORY_BONUS =

SRC = $(MANDATORY:%=$(SRC_DIR)%.c)
OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

SRC_BONUS = $(MANDATORY_BONUS:%=%.c)
OBJ_BONUS = $(SRC_BONUS:%.c=$(OBJ_DIR)%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	 $(CC) $(HEADER_DIR) $(OBJ) $(LIBFT)/libft.a $(PRINTF)/libftprintf.a -o $(NAME)

$(OBJ_DIR)%.o :$(SRC_DIR)%.c $(OBJ_DIR) lib
	@$(CC) $(CFLAGS) $(HEADER_DIR) -c $< -o $@ -g

lib :
	cd $(LIBFT); make; cd ../..; cp $(LIBFT)/libft.h includes/; \
	cd $(PRINTF); make; cd ../..; cp $(PRINTF)/includes/ft_printf.h includes/;

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

re	: fclean all
	
clean :
	rm -rf $(OBJ_DIR)

fclean : clean 
	rm -f $(NAME) a.out

.PHONY : re clean fclean test lib
