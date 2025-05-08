NAME		= miniRT

CC			= cc
CFLAGS		= -Wall -Werror -Wextra

CPPFLAGS	= -I includes/ -I mlx
LDFLAGS		= -L biglibft/
LDLIBS		= -lft -lmlx -Lmlx -L /usr/lib -lX11 

MANDATORY	= main

SRC_DIR	= src/
TMP_DIR = tmp/

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(MANDATORY)))
OBJ = $(addprefix $(TMP_DIR), $(addsuffix .o, $(notdir $(MANDATORY))))
DEP = $(addprefix $(TMP_DIR), $(addsuffix .d, $(notdir $(MANDATORY))))

all : $(NAME)

$(NAME) :	$(TMP_DIR) mlx $(OBJ) $(DEP) 

-include $(DEP)
-include biglibft/Makefile

$(TMP_DIR) :
	mkdir -p $(TMP_DIR)

mlx :
	git clone https://github.com/42paris/minilibx-linux.git mlx
	cd mlx; ./configure


