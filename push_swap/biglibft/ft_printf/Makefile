CC = cc
CFLAGS 	= -Wall -Werror -Wextra -fPIE
NAME 	= libftprintf.a

SRC_DIR 	=	src/
HEADER_DIR	=	-I header/
OBJ_DIR		=	obj/

MANDATORY = ft_special_atoi ft_memset ft_printf_atrib_utils ft_printf_buf_utils \
			ft_printf ft_printf_tobuf_nb ft_printf_tobuf_nb_utils \
			ft_printf_tobuf_strchr ft_printf_utils

SRC = $(MANDATORY:%=$(SRC_DIR)%.c)
OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all : $(NAME)

$(OBJ_DIR)%.o :$(SRC_DIR)%.c $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(HEADER_DIR) -c $< -O3 -o $@

$(NAME) : $(OBJ)	
	ar rcs $(NAME) $(OBJ)

re	: fclean all
	
clean :
	rm -rf $(OBJ_DIR)

fclean : clean 
	rm -f $(NAME) a.out

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

.PHONY : re clean fclean test
