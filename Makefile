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

test: $(NAME)
	$(CC) $(CFLAGS) -o test_ft_printf test_ft_printf.c $(FT_PRINTF_OBJS) $(LIBFT_OBJS) -I. -L. -lftprintf

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f test_ft_printf

re: fclean all

.PHONY: all clean fclean re
