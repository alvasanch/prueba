/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvasanc <alvasanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:24:53 by alvasanc          #+#    #+#             */
/*   Updated: 2024/01/29 11:38:48 by alvasanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(long number)
{
	int	i;

	i = 1;
	while (number >= 10)
	{
		number = number / 10;
		i++;
	}
	return (i);
}

int	ft_printunint(unsigned int number)
{
	long	long_number;
	int		printed_chars;
	long	aux;

	aux = 0;
	printed_chars = 1;
	long_number = (long)number;
	if (long_number < 0)
		long_number = 4294967295 + long_number;
	aux = long_number;
	if (long_number > 9)
	{
		ft_printunint((unsigned int)(long_number / 10));
		ft_putchar(long_number % 10 + '0');
	}
	else
		ft_putchar(long_number + '0');
	printed_chars = ft_count(aux);
	return (printed_chars);
}
