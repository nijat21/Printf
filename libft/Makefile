.PHONY: all clean flcean re

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRCS := ft_isalnum.c ft_itoa.c ft_memchr.c ft_putchar_fd.c \
        ft_strchr.c ft_strlcpy.c ft_strrchr.c ft_isalpha.c \
        ft_memcmp.c ft_putendl_fd.c ft_strdup.c ft_strlen.c \
        ft_strtrim.c ft_atoi.c ft_isascii.c ft_memcpy.c ft_putnbr_fd.c \
        ft_striteri.c ft_strmapi.c ft_substr.c ft_bzero.c ft_isdigit.c \
        ft_memmove.c ft_putstr_fd.c ft_strjoin.c \
        ft_strncmp.c ft_tolower.c ft_calloc.c ft_isprint.c \
        ft_memset.c ft_split.c ft_strlcat.c ft_strnstr.c ft_toupper.c

BONUS_SRC := ft_lstiter.c ft_lstlast.c ft_lstadd_back.c ft_lstadd_front.c ft_lstmap.c \
		ft_lstclear.c ft_lstnew.c ft_lstdelone.c ft_lstsize.c 

OBJS := $(SRCS:%.c=%.o)
BONUS_OBJS := $(BONUS_SRC:%.c=%.o)

all: ${NAME}

${NAME}: ${OBJS}
	@echo "Linking libft.a"
	ar rcs ${NAME} ${OBJS}

bonus: ${NAME} ${BONUS_OBJS}
	ar rcs ${NAME} ${BONUS_OBJS}
	touch bonus

%.o: %.c libft.h
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -fv ${OBJS} ${BONUS_OBJS} bonus

fclean: clean
	rm -f ${NAME}

re: fclean all