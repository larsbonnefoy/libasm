# Define the compiler and compiler flags
CC = clang
NASM = nasm
CFLAGS = -Wall -Wextra -Werror -g

# Define the source and object file names

SRC_ASM = ft_strcmp.s ft_strcpy.s ft_strlen.s ft_write.s ft_read.s
SRC_C = main.c

OBJ_DIR = obj
OBJ_ASM = $(addprefix $(OBJ_DIR)/, $(SRC_ASM:.s=.o))
OBJ_C = $(addprefix $(OBJ_DIR)/, $(SRC_C:.c=.o))

# Define the output executable name
EXECUTABLE = test

# Default target
all: $(EXECUTABLE)

# Create the object directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compile assembly files to object files
$(OBJ_DIR)/%.o: %.s | $(OBJ_DIR)
	$(NASM) -fmacho64 $< -o $@

# Compile C source files to object files
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files to create the executable
$(EXECUTABLE): $(OBJ_ASM) $(OBJ_C)
	$(CC) $(CFLAGS) $(OBJ_ASM) $(OBJ_C) -o $@

# Clean up intermediate and executable files
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(EXECUTABLE)

re: fclean all

.PHONY: all clean fclean re

