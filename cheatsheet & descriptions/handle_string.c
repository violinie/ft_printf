#include "ft_printf.h"

int	handle_string(char *str)
{
	// if there is nothing, return "null" to standard output (1)
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1); // prints the contents of the str string to standard output (1)
	return (ft_strlen(str)); // return length of the array
}
