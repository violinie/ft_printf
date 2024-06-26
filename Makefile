NAME = libftprintf.a

SRCS = ft_printf.c \
		handle_char.c \
		handle_string.c \
		handle_unsigned.c \
		handle_integer.c \
		handle_hex.c \

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	cp $(LIBFT) .
	mv libft.a $(NAME)
	$(AR) $@ $^

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
