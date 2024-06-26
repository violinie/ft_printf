#include "ft_printf.h"

int	handle_unsigned(long u)
{
	char	*str;
	int		len;


	str = ft_itoa(u);
	len = handle_string(str);
	free(str);
	return (len);
}

// long u
// is it negative? 


/*
	TEST(2, print(" %u ", -1));

	TEST(13, print(" %u ", -9));
	TEST(14, print(" %u ", -10));
	TEST(15, print(" %u ", -11));
	TEST(16, print(" %u ", -14));
	TEST(17, print(" %u ", -15));
	TEST(18, print(" %u ", -16));
	TEST(19, print(" %u ", -99));
	TEST(20, print(" %u ", -100));
	TEST(21, print(" %u ", -101));

	TEST(23, print(" %u ", INT_MIN));
	TEST(24, print(" %u ", LONG_MAX));

	TEST(26, print(" %u ", UINT_MAX));
	TEST(27, print(" %u ", ULONG_MAX));
	TEST(28, print(" %u ", 9223372036854775807LL));
	TEST(29, print(" %u %u %u %u %u %u %u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));*/
