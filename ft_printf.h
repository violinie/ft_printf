#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include "libft/libft.h"

int	ft_printf(const char *format, ...);
int	handle_char(char c);
int	handle_string(char *str);
int handle_unsigned(unsigned long u);
int	handle_integer(int nb);
int	handle_hex(unsigned int unb, int uppercase);
int	handle_pointer(uintptr_t n);

#endif
