#include "ft_printf.h"

int	handle_unsigned(unsigned int u)
{
	char	*str;
	int		len;

	str = ft_itoa(u);
	len = handle_string(str);
	free(str);
	return (len);
}
