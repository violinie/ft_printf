#include "ft_printf.h"

// handle different format specifiers
static void	handle_conversion(char c, va_list args, int *count)
{
	if (c == 'c') // if the format specifier is 'c' (character)
		*count = *count + handle_char((char)va_arg(args, int)); // TODO
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
