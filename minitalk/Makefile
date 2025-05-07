CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -MMD -MP

LINKFLAGS		= 

NAME			= client server

SRC_DIR			= src
CLIENT_SRC_DIR	= $(SRC_DIR)/client
SERVER_SRC_DIR	= $(SRC_DIR)/server

OBJ_DIR			= obj
CLIENT_OBJ_DIR	= $(OBJ_DIR)/client
SERVER_OBJ_DIR	= $(OBJ_DIR)/server

HEADER_DIR		= -I header -I biglibft/header

LIB				= -L biglibft -lft

CLIENT			= main send
SERVER			= main get

CLIENT_SRC		= $(CLIENT:%=$(CLIENT_SRC_DIR)/%.c)
SERVER_SRC		= $(SERVER:%=$(SERVER_SRC_DIR)/%.c)

CLIENT_OBJ		= $(CLIENT_SRC:$(CLIENT_SRC_DIR)/%.c=$(CLIENT_OBJ_DIR)/%.o)
SERVER_OBJ		= $(SERVER_SRC:$(SERVER_SRC_DIR)/%.c=$(SERVER_OBJ_DIR)/%.o)

CLIENT_DEPS		= $(CLIENT_SRC:$(CLIENT_SRC_DIR)/%.c=$(CLIENT_OBJ_DIR)/%.d)
SERVER_DEPS		= $(SERVER_SRC:$(SERVER_SRC_DIR)/%.c=$(SERVER_OBJ_DIR)/%.d)

all	: 	init $(NAME)

$(OBJ_DIR)/%.o	: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(HEADER_DIR) -c $< -o $@

-include $(CLIENT_DEPS) $(SERVER_DEPS)

client	: $(CLIENT_OBJ)
	$(CC) $(CLIENT_OBJ) $(LIB) $(LINK_FLAGS) -o $@

server	: $(SERVER_OBJ)
	$(CC) $(SERVER_OBJ) $(LIB) $(LINK_FLAGS) -o $@

re	: fclean all bonus

bonus	: all

clean	:
	rm -f  client server 

fclean	: clean
	rm -rf $(OBJ_DIR)

init	: 
	@mkdir -p $(OBJ_DIR) $(CLIENT_OBJ_DIR) $(SERVER_OBJ_DIR)

PHONY	: clean fclean init 

