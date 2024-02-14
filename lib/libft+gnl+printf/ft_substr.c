/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvasanc <alvasanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:42:37 by alvasanc          #+#    #+#             */
/*   Updated: 2023/09/29 13:46:37 by alvasanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;
	size_t	j;

	i = start;
	j = 0;
	if (ft_strlen(s) == 0 || len <= 0 || start < 0 || start > ft_strlen(s))
		return (ft_calloc(1, 1));
	while (s[i] && j <= len - 1)
	{
		i++;
		j++;
	}
	substring = (char *)malloc((j + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	j = 0;
	while (s[start] && j <= len - 1)
	{
		substring[j] = s[start];
		j++;
		start++;
	}
	substring[j] = '\0';
	return (substring);
}
