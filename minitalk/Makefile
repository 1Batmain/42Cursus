CC = cc
CFLAGS 	= -Wall -Werror -Wextra
NAME 	= minitalk


all : $(NAME)

$(NAME) : 	
	cd server_files; make; cd ../client_files; make;

re	:
	cd server_files; make re; cd ../client_files; make re	

clean :
	cd server_files; make clean; cd ../client_files; make clean

fclean :
	cd server_files; make fclean; cd ../client_files; make fclean


.PHONY : re clean fclean test
