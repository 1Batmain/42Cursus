CC = cc
CFLAGS 	= -Wall -Werror -Wextra
NAME 	= libftprintf.a

SRC_DIR 	=	srcs/
HEADER_DIR	=	-I includes/
OBJ_DIR		=	obj/

MANDATORY = ft_special_atoi ft_memset ft_printf_atrib_utils ft_printf_buf_utils \
			ft_printf ft_printf_tobuf_nb ft_printf_tobuf_nb_utils \
			ft_printf_tobuf_strchr ft_printf_utils

SRC = $(MANDATORY:%=$(SRC_DIR)%.c)
OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

SRC_BONUS = $(MANDATORY_BONUS:%=%.c)
OBJ_BONUS = $(SRC_BONUS:%.c=$(OBJ_DIR)%.o)

all : $(NAME)

$(OBJ_DIR)%.o :$(SRC_DIR)%.c $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(HEADER_DIR) -c $< -o $@

$(NAME) : $(OBJ)	
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

bonus : $(OBJ) $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ) $(OBJ_BONUS)

re	: fclean all
	
clean :
	rm -rf $(OBJ_DIR)

fclean : clean 
	rm -f $(NAME) a.out

test : $(OBJ)
	@$(CC) $(CFLAGS) $(HEADER_DIR) -g $(OBJ) $(TEST_MAIN)

.PHONY : re clean fclean test
