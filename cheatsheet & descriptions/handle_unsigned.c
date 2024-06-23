#include "ft_printf.h"

int	handle_unsigned(unsigned int u)
{
	char	*str; // pointer to hold the string representation of the number
	int		len; // Variable to hold the length of the string

	str = ft_itoa(u); // convert the unsigned integer to a string
	len = handle_string(str); // pass the string to handle_string function and get the length
	free(str); // free the allocated memory for the string
	return (len); // return the length of the string
}
