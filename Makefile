SRC_DIR = src
# SRC_DIR = $(shell pwd)/src
# OBJ_DIR = $(shell pwd)/objs
OBJ_DIR = objs
LIBFT_DIR = libft
# INCLUDES = $(shell pwd)

SRC_FILES = ft_printf.c		formatters.c \
			handlers.c		handlers2.c \
			parsers.c

SRC_FILES := $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

CC = cc
CFLAGS = -Wall -Werror -Wextra -I.
AR = ar rcs
RM = rm -f

LIBFT = $(LIBFT_DIR)/libft.a
NAME = libftprintf.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	@echo "Compiling libft..."
	@$(MAKE) -C $(LIBFT_DIR)
	@cp libft/libft.a .
	@echo "libft compiled successfully."

prova:
	echo $(OBJS)

$(NAME): $(OBJS) Makefile
	@echo "Creating static library $(NAME)... 📚"
	@$(AR) $(NAME) $(OBJS)
	@echo "Library $(NAME) created successfully. ✅"


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c ft_printf.h 
# $(OBJ_DIR)/srcs/%.o: $(SRC_DIR)/%.c libftprintf.h | $(OBJ_DIR)
	@echo "Compiling $<... 🛠️"
	@mkdir -p $(OBJ_DIR)/srcs/
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Removing object files from ft_printf... 🧹"
	@$(RM) -r $(OBJ_DIR)
	@echo "Object files removed at ft_printf. ✅"

fclean: clean
	@echo "Removing libraries and executable from ft_printf... 🗑️"
	@$(RM) $(NAME) libft.a
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "Cleanup complete. ✅"

re: fclean all
	@echo "Full recompilation complete. 🎉"

.PHONY: all bonus fclean clean re prova
