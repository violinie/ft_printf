#include "ft_printf.h"

int	handle_pointer(uintptr_t n)
{
	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	return (ft_printf_hexptr(n));
}
