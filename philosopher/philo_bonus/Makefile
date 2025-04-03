CC			= cc
CFLAGS		= -Wall -Werror -Wextra -MMD -MP -g

NAME		= philo_bonus
HEADER		= -I header/
LIB			= -pthread

SRC_DIR		= src/
OBJ_DIR		= obj/

MANDATORY	= main table utils args error philosopher action print_action eat watcher

SRC			= $(MANDATORY:%=$(SRC_DIR)%.c)
OBJ			= $(MANDATORY:%=$(OBJ_DIR)%.o)
DEP			= $(MANDATORY:%=$(OBJ_DIR)%.d)

all	: $(NAME)

$(OBJ_DIR)%.o	: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

-include $(DEP)

$(NAME)	: $(OBJ)
	$(CC) $(LIB) $^ -o $@

semclean : all
	rm $(addprefix /dev/shm/sem., END FORKS PRINTF PHILO); 
clear	:
	clear
clean	:
	rm $(NAME)

fclean	: clean
	rm -rf $(OBJ_DIR)

re	: fclean all

PHONY	: re fclean clean
