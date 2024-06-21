#include "ft_printf.h"

// handle different format specifiers
static void	handle_conversion(char c, va_list args, int *count)
{
	if (c == 'c') // if the format specifier is 'c' (character)
		// gets the next argument from a variable list of arguments (va_arg(args, int))
		// because variadic arguments are promoted to int (ASCII value), transforms the obtained integer into a character ((char)va_arg(args, int))
		// passes the character to the handle_char function for printing (handle_char((char)va_arg(args, int)))
		// adds the number of characters printed by the handle_char function to the total number of characters printed
		*count = *count + handle_char((char)va_arg(args, int));
	else if (c == 's')
		*count = *count + handle_string(va_arg(args, char *)); // similar to handle_char
	else if (c == 'd' || c == 'i')
		*count = *count + handle_int(va_arg(args, int));
	else if (c == 'u')
		*count = *count + handle_unsigned(va_arg(args, unsigned int));
	else if (c == '%')
		*count = *count + handle_char(c); // passing just the %
}

// custom printf function
// const char *format == for example "%c\n"
// ... == can accept variable number of arguments (ellipsis or variadic argument)
int	ft_printf(const char *format, ...)
{
	va_list	args; // declare a variable to hold the list of arguments
	int		count; // variable to count the number of characters printed

	count = 0;
	va_start(args, format); // initialize the va_list 'args' to start at the argument after 'format'
	while (*format) // loop through each character in the format string
    {
		if (*format == '%' && *(format + 1)) // if a format specifier is found
		{
			format++; // move to the next character (the specifier)
			handle_conversion(*format, args, &count); // handle the conversion
		}
		else // if it's not a format specifier
		{
			write(1, format, 1); // write the character to standard output
			count++; // increment the count of printed characters
		}
		format++; // move to the next character in the format string
	}
	va_end(args); // clean up the argument list
	return (count); // return the total number of characters printed
}

/*int	main(void)
{
    int count1, count2;

    // Test with a single character
    char test_char = 'A';
    count1 = printf("Standard printf: %c\n", test_char);
    count2 = ft_printf("Custom ft_printf: %c\n", test_char);

    printf("Standard printf returned: %d characters\n", count1);
    ft_printf("Custom ft_printf returned: %d characters\n", count2);

    // Test with multiple characters
    count1 = printf("Standard printf: %c %c %c\n", 'A', 'B', 'C');
    count2 = ft_printf("Custom ft_printf: %c %c %c\n", 'A', 'B', 'C');

    printf("Standard printf returned: %d characters\n", count1);
    ft_printf("Custom ft_printf returned: %d characters\n", count2);

    return 0;
}*/
