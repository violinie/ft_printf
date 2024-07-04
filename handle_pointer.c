#include "ft_printf.h"

static int	ft_strrev(char *str)
{
	char	*rev;
	int		i;
	int		j;
	int		count;

	i = 0;
	j = ft_strlen(str) + 1;
	rev = malloc(j * sizeof(char));
	if (!rev)
		return (0);
	j--;
	rev[j] = 0;
	j--;
	while (j >= 0)
	{
		rev[j] = str[i];
		j--;
		i++;
	}
	free(str);
	count = handle_string(rev);
	free(rev);
	return (count);
}

static char	convert_to_hex(uintptr_t mod)
{
	if (mod == 10)
		return ('a');
	else if (mod == 11)
		return ('b');
	else if (mod == 12)
		return ('c');
	else if (mod == 13)
		return ('d');
	else if (mod == 14)
		return ('e');
	else if (mod == 15)
		return ('f');
	return ('0' + mod);
}

static int	convert_pointer_to_hex(uintptr_t unb)
{
	int	i;

	i = 0;
	while (unb > 0)
	{
		unb = unb / 16;
		i++;
	}
	return (i);
}

static int	count_hex_digits(uintptr_t unb)
{
	char			*str;
	int				i;
	int				count;

	if (unb == 0)
		return (handle_string("0"));
	str = ft_calloc(convert_pointer_to_hex(unb) + 1, sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (unb > 0)
	{
		str[i] = convert_to_hex(unb % 16);
		unb = unb / 16;
		i++;
	}
	count = ft_strrev(str);
	return (count);
}

int	handle_pointer(uintptr_t n)
{
	int count;

	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	count = count_hex_digits(n);
	return (count + 2);
}
