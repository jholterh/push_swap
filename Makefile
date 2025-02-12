# Compiler
CC = cc

# Flags
CFLAGS = -v #need to add flags!!!

# Directories
HEADER_DIR = header
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft

# Libraries
LIBS = -L$(LIBFT_DIR) -lft

# Source files
SRC = src/push_swap.c \
		src/helper_functions.c \
		src/check_input.c \
		src/instructions.c \
		src/algorythm.c

# Object files
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Executable name
NAME = push_swap

# Include directories
INCLUDES = -I$(HEADER_DIR)

# Rules
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_DIR)/libft.a
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
