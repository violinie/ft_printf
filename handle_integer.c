#include "ft_printf.h"

int	handle_integer(int nb)
{
	char	*str;
	int		len;

	str = ft_itoa(nb);
	len = handle_string(str);
	free(str);
	return (len);
}
