#include "ft_printf.h"

static void	handle_conversion(char c, va_list args, int *count)
{
	if (c == 'c')
		*count = *count + handle_char((char)va_arg(args, int));
	else if (c == 's')
		*count = *count + handle_string(va_arg(args, char *));
	else if (c == 'u')
		*count = *count + handle_unsigned(va_arg(args, unsigned int));
	else if (c == '%')
		*count = *count + handle_char(c);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			handle_conversion(*format, args, &count);
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
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

// gcc -Wall -Wextra -Werror -o test_ft_printf ft_printf.c ft_printf.h handle_char.c libft/ft_putchar_fd.c
