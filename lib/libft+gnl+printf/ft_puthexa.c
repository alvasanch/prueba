/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvasanc <alvasanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:10:56 by alvasanc          #+#    #+#             */
/*   Updated: 2024/01/29 11:39:12 by alvasanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sethexa(unsigned long number, char *base, int printed_chars)
{
	if (number > 15)
	{
		printed_chars = ft_sethexa(number / 16, base, printed_chars);
		write (1, &(base[number % 16]), 1);
		printed_chars++;
	}
	else
	{
		write (1, &(base[number]), 1);
		printed_chars++;
	}
	return (printed_chars);
}

int	ft_puthexa(unsigned long i, char c)
{
	char	*lower_base;
	char	*upper_base;
	int		printed_chars;

	lower_base = "0123456789abcdef";
	upper_base = "0123456789ABCDEF";
	printed_chars = 0;
	if (c == 'X')
		printed_chars = ft_sethexa((unsigned int)i, upper_base, printed_chars);
	else if (c == 'x')
		printed_chars = ft_sethexa((unsigned int)i, lower_base, printed_chars);
	else if (c == 'p')
	{
		write(1, "0x", 2);
		printed_chars = ft_sethexa(i, lower_base, printed_chars);
		printed_chars += 2;
	}
	return (printed_chars);
}
