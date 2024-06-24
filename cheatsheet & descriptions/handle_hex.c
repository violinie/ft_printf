#include "ft_printf.h"

// reverse a string and handle it
static int	ft_strrev(char *str)
{
	char	*rev; // pointer to hold the reversed string
	size_t	i; // index for original string
	size_t	r; // index for reversed string
	size_t	count; // variable to hold the length of the handled string

	i = 0;
	r = ft_strlen(str) + 1; // get length of the string plus one for the null terminator
	rev = malloc(r * sizeof(char)); // allocate memory for the reversed string
	// if allocation fails, return 0
	if (!rev)
		return (0);
	r--; // decrement r to point to the last valid index in the allocated memory
	rev[r] = 0; // null terminate the reversed string
	r--; // decrement to start filling the reversed string from the end
	// reverse the string
	while (r >= 0)
	{
		rev[r] = str[i];
		r--;
		i++;
	}
	free(str); // free the original string
	count = handle_string(rev); // handle the reversed string and get the length
	free(rev); // free the reversed string
	return (count); // return the length of the handled string
}

static char	ft_convert(unsigned int mod)
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
			str[i++] = ft_convert(mod) - 32;
		else if (mod > 9)
			str[i++] = ft_convert(mod);
		else
			str[i++] = (char)(mod + 48);
		unb = unb / 16;
	}
	count = count + ft_strrev(str);
	return (count);
}
