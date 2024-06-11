NAME = libftprintf.a
CC = cc
CCFLAGS = -Wall -Werror -Wextra
RM = rm -f
LIBC = ar rc

SRCS = \
ft_printf.c \

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

%.o: %.c
	${CC} ${CCFLAGS} -c $< -o $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
