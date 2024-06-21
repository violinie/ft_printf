#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include "libft/libft.h"

int	ft_printf(const char *format, ...);
int	handle_char(char c);
int	handle_string(char *str);
int	handle_unsigned(unsigned int u);
int	handle_integer(int nb);

#endif
