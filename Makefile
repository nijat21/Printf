.PHONY: all clean fclean re

LIB_DIR = ./libft
LIBRARY = $(LIB_DIR)/libft.a

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS := ft_printf.c print_hex.c print_pointer.c print_unsigned_number.c print_char.c print_number.c print_string.c
BONUS_SRCS := bonus1.c

OBJS := $(SRCS:%.c=%.o)
BONUS_OBJS :=$(BONUS_SRCS:%.c=%.o)

all: $(LIBRARY) $(NAME)

$(LIBRARY):
	@echo "Creating libft library"
	$(MAKE) -C $(LIB_DIR)

$(NAME): $(OBJS) $(LIBRARY)
	@echo "Creating libftprintf.a"
	ar rcs $(NAME) $^

bonus: $(NAME) $(LIBRARY) $(BONUS_OBJS)
	@echo "Adding bonus objects to libftprintf.a"
	ar rcs $(NAME) $(LIBRARY) $(BONUS_OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning objects..."
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@echo "Cleaning libft and libftprintf..."
	$(MAKE) -C $(LIB_DIR) fclean
	rm -fv $(NAME) 

re: fclean all