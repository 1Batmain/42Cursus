NAME 		= fdf

CC 			= cc
CFLAGS		= -Wall -Werror -Wextra

MANDATORY	= main map draw_line utils key_handle center_normalize \
			  rotate_translate

SRC_DIR		= src/
OBJ_DIR		= obj/
HEADER		= -I header/ -I /usr/include -I mlx_linux -I biglibft/header
LIB			= -L mlx_linux -lmlx_Linux -L /usr/lib -L biglibft -lXext -lX11 -lm -lz -lft

#-Imlx_linux
SRC		= $(MANDATORY:%=$(SRC_DIR)%.c)
OBJ		= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
DEP		= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR).d)

all : $(OBJ_DIR) .lib $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@ -g

-include $(DEP)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) $(LIB) -o $@ -g

$(OBJ_DIR) :
	mkdir -p $@

.lib	:
	@cd biglibft; make; cd ..;
	@cd mlx_linux; ./configure; cd ..;
	@touch $@

clean : 
	rm -rf $(OBJ_DIR)

fclean : clean
	rm $(NAME)

re : fclean all 

.PHONY : clean fclean
