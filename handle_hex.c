#include "ft_printf.h"

static int	ft_strrev(char *str)
{
	char	*rev;
	size_t	i;
	size_t	j;
	size_t	count;

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

static char	convert_to_hex(unsigned int mod)
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
	return (mod);
}

static int	ft_places(unsigned int unb)
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

int	handle_hex(unsigned int unb, int uppercase)
{
	char			*str;
	unsigned int	mod;
	int				i;
	int				count;

	count = 0;
	if (unb == 0)
		return (handle_char('0'));
	str = ft_calloc(ft_places(unb) + 1, sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (unb > 0)
	{
		mod = unb % 16;
		if (mod > 9 && uppercase)
			str[i++] = convert_to_hex(mod) - 32;
		else if (mod > 9)
			str[i++] = convert_to_hex(mod);
		else
			str[i++] = (char)(mod + 48);
		unb = unb / 16;
	}
	count = count + ft_strrev(str);
	return (count);
}
