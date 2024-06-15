#include "ft_printf.h"

int	handle_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
