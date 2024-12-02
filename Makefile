LIB_DIR = ./libft
LIBRARY = $(LIB_DIR)/libft.a

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS := ft_printf.c print_hex.c print_pointer.c print_unsigned_number.c print_char.c print_number.c print_string.c

OBJS := $(SRCS:%.c=%.o)

all: $(LIBRARY) $(NAME)

$(LIBRARY):
	$(MAKE) -C $(LIB_DIR)

$(NAME): $(OBJS) $(LIBRARY)
	ar rcs $(NAME) $(OBJS)
	ar -x $(LIBRARY)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIB_DIR) fclean
	rm -fv $(NAME) 

re: fclean all

.PHONY: all clean fclean re