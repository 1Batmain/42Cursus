NAME	= libft.a

CC		= cc
CFLAGS	= -Wall -Werror -Wextra

all : $(NAME)

$(NAME) :
	cd libft; make; cd ..;\
	cd ft_printf; make; cd ..;\
	cp -r libft/header ft_printf/header .;\
	ar -rcT $(NAME) libft/libft.a ft_printf/libftprintf.a 

clean :
	cd libft; make clean; cd ..;\
	cd ft_printf; make clean; cd ..;

fclean :
	cd libft; make fclean; cd ..;\
	cd ft_printf; make fclean; cd ..;\
	rm $(NAME)

re : fclean all
