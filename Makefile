.PHONY: all clean fclean re

LIB_DIR = ./libft
LIBRARY = $(LIB_DIR)/libft.a

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS := $(shell find . -name '*.c')
OBJS := $(SRCS:%.c=%.o)

all: $(LIBRARY) $(NAME)

$(LIBRARY):
	@echo "Creating libft library"
	$(MAKE) -C $(LIB_DIR)

$(NAME): $(OBJS)
	@echo "Creating libftprintf.a"
	ar rcs $(NAME) $(OBJS)

%.0: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning objects..."
	rm -f $(OBJS)

fclean: clean
	@echo "Cleaning libft and libftprintf..."
	$(MAKE) -C $(LIB_DIR) fclean
	rm -fv $(NAME) 

re: fclean all