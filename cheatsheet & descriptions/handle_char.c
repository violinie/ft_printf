/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanacop <hanacop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:20:45 by hanacop           #+#    #+#             */
/*   Updated: 2024/06/16 20:45:33 by hanacop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_char(char c)
{
	ft_putchar_fd(c, 1); // calling ft_putchar_fd with argument of c and 1 as standard output
	return (1);
}
