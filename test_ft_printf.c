/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanacop <hanacop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:26:19 by hanacop           #+#    #+#             */
/*   Updated: 2024/06/16 20:26:38 by hanacop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void) {
	int count1;
	int	count2;
	char test_char;

	// Test with a single character
	test_char = 'A';
	count1 = printf("Standard printf: %c\n", test_char);
	count2 = ft_printf("Custom ft_printf: %c\n", test_char);
	printf("Standard printf returned: %d characters\n", count1);
	ft_printf("Custom ft_printf returned: %d characters\n", count2);
	// Test with multiple characters
	count1 = printf("Standard printf: %c %c %c\n", 'A', 'B', 'C');
	count2 = ft_printf("Custom ft_printf: %c %c %c\n", 'A', 'B', 'C');
	printf("Standard printf returned: %d characters\n", count1);
	ft_printf("Custom ft_printf returned: %d characters\n", count2);
	return (0);
}
