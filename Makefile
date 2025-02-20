SRC_DIR = src
OBJ_DIR = objs
LIBFT_DIR = libft

SRC_FILES = ft_printf.c		formatters.c \
			handlers.c		handlers2.c \
			parsers.c		printers.c

SRC_FILES := $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

CC = cc
CFLAGS = -Wall -Werror -Wextra -I.
AR = ar rcs
RM = rm -f

LIBFT = $(LIBFT_DIR)/libft.a
NAME = libftprintf.a

all: $(NAME)

$(LIBFT): Makefile
	@echo "Compiling libft..."
	@make -C $(LIBFT_DIR)
	@cp libft/libft.a ./libft.a
	@echo "libft compiled successfully."

$(NAME): $(OBJS) $(LIBFT) Makefile
	@echo "Creating static library $(NAME)... 📚"
	@cp $(LIBFT) $(NAME)
	@$(AR) $(NAME) $(OBJS)
	@echo "Library $(NAME) created successfully. ✅"


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c ft_printf.h 
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

.PHONY: all bonus fclean clean test re
