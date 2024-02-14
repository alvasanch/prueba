/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvasanc <alvasanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:19:06 by alvasanc          #+#    #+#             */
/*   Updated: 2023/10/11 10:45:59 by alvasanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static	int	ft_countword(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static	int	ft_next_del(char const *s, char c, int i)
{
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	size_t	i;
	size_t	number_words;
	size_t	j;

	number_words = ft_countword(s, c);
	matrix = (char **) malloc((number_words + 1) * sizeof(char *));
	if (!matrix)
		return (NULL);
	matrix[number_words] = NULL;
	i = 0;
	j = 0;
	while (j < number_words && s[i] != '\0')
	{
		if (s[i] != c)
		{
			matrix[j++] = ft_substr(s, i, (ft_next_del(s, c, i) - i));
			if (!matrix[j - 1])
				return (ft_free(matrix));
			i = ft_next_del(s, c, i);
		}
		else
			i++;
	}
	return (matrix);
}
