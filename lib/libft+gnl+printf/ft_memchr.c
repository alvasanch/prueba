/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvasanc <alvasanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:13:43 by alvasanc          #+#    #+#             */
/*   Updated: 2023/09/26 13:25:30 by alvasanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*string;
	char	target;
	size_t	i;

	string = ((char *)s);
	target = ((char)c);
	i = 0;
	while (i < n)
	{
		if (string[i] != target)
			i++;
		else
			return ((char *)&s[i]);
	}
	return (0);
}
