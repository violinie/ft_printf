#include "ft_printf.h"

char	*itoa_unsigned(unsigned long u)
{
	char	*str;
	int	len;

	len = snprintf(NULL, 0, "%lu", u);
	str = malloc(len + 1);
	if (str != NULL) {
		snprintf(str, len + 1, "%lu", u);
	}
	return str;
}

int handle_unsigned(unsigned long u)
{
	char	*str;
	int	len;

	str = itoa_unsigned(u);
	len = handle_string(str);
	free(str);
	return (len);
}

/*int	handle_unsigned(long u)
{
	char	*str;
	int		len;


	str = ft_itoa(u);
	len = handle_string(str);
	free(str);
	return (len);
}*/

/*
	TEST(24, print(" %u ", LONG_MAX));

	TEST(26, print(" %u ", UINT_MAX));
	TEST(27, print(" %u ", ULONG_MAX));
	TEST(28, print(" %u ", 9223372036854775807LL));
	TEST(29, print(" %u %u %u %u %u %u %u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
*/
