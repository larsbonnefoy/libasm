# Define the compiler and compiler flags
CC = clang
NASM = nasm
AR = ar rc
NAME = libasm.a
CFLAGS = -Wall -Wextra -Werror -g

# Define the source and object file names
SRC_ASM = ft_strcmp.s ft_strcpy.s ft_strlen.s ft_write.s ft_read.s ft_strdup.s

OBJ_DIR = obj
OBJ_ASM = $(addprefix $(OBJ_DIR)/, $(SRC_ASM:.s=.o))

# Default target
all: $(NAME)

# Create the object directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compile assembly files to object files
$(OBJ_DIR)/%.o: %.s | $(OBJ_DIR)
	$(NASM) -fmacho64 $< -o $@

# Link object files to create the executable
$(NAME): $(OBJ_ASM) $(OBJ_C)
	$(AR) $(NAME) $(OBJ_ASM)

# Clean up intermediate and executable files
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

