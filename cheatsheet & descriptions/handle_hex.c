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

// convert an integer to its corresponding hexadecimal character
static char	convert_to_hex(unsigned int mod)
{
	if (mod == 10) // if the integer is 10, return 'a'
		return ('a');
	else if (mod == 11) // if the integer is 11, return 'b'
		return ('b');
	else if (mod == 12) // if the integer is 12, return 'c'
		return ('c');
	else if (mod == 13) // if the integer is 13, return 'd'
		return ('d');
	else if (mod == 14) // if the integer is 14, return 'e'
		return ('e');
	else if (mod == 15) // if the integer is 15, return 'f'
		return ('f');
	return (mod); // if the integer is not between 10 and 15, return the integer itself
}

// calculates the number of digits required to represent an unsigned integer in hexadecimal (base 16 == 0 - 9 & A - F)
static int	hex_digit_count(unsigned int unb)
{
	size_t	i; // variable to store the number of digits

	i = 0; // starting with 0
	while (unb > 0) // loop until the number is greater than 0
	{
		unb = unb / 16; // divide the number by 16 to shift to the next digit
		i++; // increment the digit counter
	}
	return (i); // return the total number of digits
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
	str = ft_calloc(hex_digit_count(unb) + 1, sizeof(char));
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
