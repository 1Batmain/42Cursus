CC = cc
CFLAGS 	= -Wall -Werror -Wextra
NAME 	= client

SRC_DIR 	=	srcs/
HEADER_DIR	=	-I includes/ -I ../biglibft/header
OBJ_DIR		=	objs/
LIB_DIR		=	../biglibft
LIB			= -L ../biglibft -lft

MANDATORY = main

SRC = $(MANDATORY:%=$(SRC_DIR)%.c)
OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

SRC_BONUS = $(MANDATORY_BONUS:%=%.c)
OBJ_BONUS = $(SRC_BONUS:%.c=$(OBJ_DIR)%.o)

all : $(NAME)

$(NAME) : $(OBJ) 
	 $(CC) $(HEADER_DIR) $(OBJ) $(LIB) -o $(NAME)

$(OBJ_DIR)%.o :$(SRC_DIR)%.c $(OBJ_DIR) lib
	@$(CC) $(CFLAGS) $(HEADER_DIR) -c $< -o $@ -g

lib :
	cd $(LIB_DIR); make; cd ../client_files;

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

re	: fclean all
	
clean :
	rm -rf $(OBJ_DIR)

fclean : clean 
	rm -f $(NAME) a.out

.PHONY : re clean fclean test lib
