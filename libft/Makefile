#Directories
SRC_DIR = $(shell pwd)
OBJ_DIR = $(shell pwd)/objs/
INCLUDES = $(shell pwd)

# Files
SRC_FILES =	ft_atoi.c		ft_memcpy.c \
      		ft_memchr.c		ft_strrchr.c \
		ft_strdup.c		ft_striteri.c \
		ft_substr.c		ft_bzero.c \
		ft_memmove.c		ft_strjoin.c \
		ft_tolower.c		ft_calloc.c \
		ft_memset.c		ft_strlcat.c \
		ft_toupper.c		ft_isalnum.c \
		ft_putchar_fd.c		ft_strlcpy.c \
		ft_isalpha.c		ft_putendl_fd.c \
		ft_strlen.c		ft_isascii.c \
		ft_putnbr_fd.c		ft_strmapi.c \
		ft_isdigit.c		ft_putstr_fd.c \
		ft_strncmp.c		ft_isprint.c \
		ft_split.c		ft_strnstr.c \
		ft_itoa.c		ft_memcmp.c \
		ft_strchr.c		ft_strtrim.c \
		ft_lstnew.c		ft_lstadd_front.c \
		ft_lstlast.c		ft_lstclear.c \
		ft_lstdelone.c		ft_lstsize.c \
		ft_lstmap.c		ft_lstiter.c \
		ft_lstadd_back.c

# Convertimos las fuentes en objetos
OBJS = $(patsubst %.c, $(OBJ_DIR)srcs/%.o, $(SRC_FILES))

# Compiler and Flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(INCLUDES)
AR = ar rcs
RM = rm -f

# Targets
NAME = libft.a

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@echo "Creating static library ${NAME}... 📚"
	@$(AR) $(NAME) $(OBJS)
	@echo "Library ${NAME} created successfully. ✅"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)srcs/

$(OBJ_DIR)srcs/%.o: %.c libft.h | $(OBJ_DIR)
	@echo "Compiling $<... 🛠️"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Removing object files... 🧹"
	@$(RM) -r $(OBJ_DIR)
	@echo "Object files removed. ✅"

fclean: clean
	@echo "Removing libraries and executable... 🗑️"
	@$(RM) $(NAME) $(EXEC)
	@echo "Cleanup complete. ✅"

re: fclean all
	@echo "Full recompilation complete. 🎉"

.PHONY: all bonus fclean clean re
	
