/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvasanc <alvasanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:32:43 by alvasanc          #+#    #+#             */
/*   Updated: 2024/02/14 12:39:56 by alvasanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_mat(char	**mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}

char	**matdup(char	**mat)
{
	char	**copy;
	int		size;

	size = 0;
	while (mat[size])
		size++;
	copy = malloc(sizeof(char *) * size + 1);
	if (!copy)
		return (NULL);
	size = 0;
	while (mat[size])
	{
		copy[size] = strdup(mat[size]);
		if (!copy[size])
		{
			free_mat(copy);
			return (NULL);
		}
		size++;
	}
	copy[size] = NULL;
	return (copy);
}

char	*create_path(t_map_info *map_info, char *str, char *path)
{
	int		size;

	if (path)
	{
		free (path);
		path = NULL;
	}
	size = ft_strlen(map_info->path_name) + ft_strlen(str) + 1;
	path = ft_strdup(map_info->path_name);
	if (!path)
		print_error("error en memoria asignada para ruta.", map_info);
	ft_strlcat(path, str, size);
	return (path);
}

void	print_error(char *errormsg, t_map_info *map_info)
{
	free_all(map_info);
	ft_printf("%s", errormsg);
	exit(0);
}
