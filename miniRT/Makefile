NAME		= miniRT

CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g

CPPFLAGS	= -Iincludes/ -Ibiglibft/header/ -Imlx -I/usr/include/X11/
LDFLAGS		= -Lbiglibft/ -Lmlx -L/usr/lib/
LDLIBS		= -lft -lmlx -lX11 -lXext -lm -lz

LIB			= biglibft/libft.a mlx

SRC_DIR	= src/
TMP_DIR = tmp/

SRC = $(FILES:%=$(SRC_DIR)%.c)
OBJ = $(SRC:$(SRC_DIR)%.c=$(TMP_DIR)%.o)
DEP = $(OBJ:%.o=%.d)

MAKEFLAGS += --no-print-directory

FILES	=\
		 error/error \
		 mlx/init \
		 mlx/free \
		 mlx/event \
		 mlx/loop \
		 parsing/parse \
		 parsing/split_set \
		 parsing/amb_light \
		 parsing/light \
		 parsing/cam \
		 parsing/object \
		 utils/free \
		 main
			
all : $(NAME)

.PHONY :  clean fclean re

$(TMP_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

-include $(DEP)

$(NAME) :  $(LIB) $(TMP_DIR) $(OBJ)
	$(CC) $(CPPFLAGS) $(LDFLAGS) $(OBJ) $(LDLIBS) -o $@

clean :
	rm $(NAME)

fclean :
	- $(MAKE) clean
	rm -rf $(TMP_DIR)

re : fclean
	make

$(TMP_DIR) :
	@mkdir -p $(addprefix $(TMP_DIR), $(filter-out $(curr), $(sort $(dir $(FILES)))))

biglibft/libft.a :
	@$(MAKE) -C biglibft

mlx :
	git clone https://github.com/42paris/minilibx-linux.git mlx
		cd mlx; make

#<--------------	DEV_TOOLS	------------->

.PHONY : vi dev watch

watch :
	source ~/42/42_venv/bin/activate
	watch -n1 "norminette | grep -v 'OK'; make"

vi vim :
	find . -name "*.c" -exec ctags {} +
	vim $(SRC) includes/minirt.h Makefile

dev : all
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME) scene_files/scene1.rt

coma 	:= ,
space 	:= $(empty) $(empty)
empty 	:=
curr	:=./

home :
	sudo docker run -it --rm -v "$$PWD":/mnt -w /mnt dev-env bash -c "make"

docker_set :
	echo "$$DOCKER" > Dockerfile
	sudo docker build -t dev-env .

export DOCKER
define DOCKER
FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=Europe/Paris

RUN apt update && apt install -y \
	    build-essential \
		    xorg-dev \
			    libbsd-dev \
				    && rm -rf /var/lib/apt/lists/*
endef
