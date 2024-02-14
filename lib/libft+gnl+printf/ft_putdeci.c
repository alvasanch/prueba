/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdeci.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvasanc <alvasanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:52:46 by alvasanc          #+#    #+#             */
/*   Updated: 2024/01/29 11:39:03 by alvasanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putdeci(int number)
{
	int	aux;

	aux = 0;
	if (number == -2147483648)
	{
		aux += ft_putchar('-');
		aux += ft_putchar('2');
		aux += ft_putdeci(147483648);
	}
	else if (number > 9)
	{
		aux += ft_putdeci(number / 10);
		aux += ft_putdeci(number % 10);
	}
	else if (number < 0)
	{
		aux += ft_putchar('-');
		aux += ft_putdeci(-number);
	}
	else
		aux += ft_putchar(number + '0');
	return (aux);
}
