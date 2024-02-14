/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvasanc <alvasanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:19:44 by alvasanc          #+#    #+#             */
/*   Updated: 2023/10/02 12:37:56 by alvasanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	int		i;
	int		j;
	int		len1;
	int		len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	string = (char *)malloc(((len1 + len2) * sizeof(char)) + 1);
	if (!string)
		return (NULL);
	i = -1;
	while (s1[++i])
		string[i] = s1[i];
	j = 0;
	while (s2[j])
		string[i++] = s2[j++];
	string[i] = '\0';
	return (string);
}
