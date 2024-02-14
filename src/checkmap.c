/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvasanc <alvasanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:05:05 by alvasanc          #+#    #+#             */
/*   Updated: 2024/02/14 13:54:01 by alvasanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_extwalls(t_map_info *map_info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map_info->x_size)
	{
		if (map_info->map[j][i] != '1')
			return (0);
		i++;
	}
	while (++j < (map_info->y_size - 1))
	{
		if (map_info->map[j][0] != '1'
			|| map_info->map[j][map_info->x_size - 1] != '1')
			return (0);
	}
	i = 0;
	while (i < map_info->x_size)
	{
		if (map_info->map[j][i++] != '1')
			return (0);
	}
	return (1);
}

void	map_chars_check(t_map_info *map_info, char c)
{
	if (c == 'C')
		map_info->collectables++;
	else if (c == 'E')
		map_info->exits++;
	else if (c != '0' && c != '1' && c != 'P')
	{
		print_error("caracter no valido.", map_info);
	}
}

void	map_matcheck(t_map_info *map_info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map_info->map[i])
	{
		while (map_info->map[i][j])
		{
			if (map_info->map[i][j] == 'P')
			{
				map_info->p_pos_x = j;
				map_info->p_pos_y = i;
				map_info->players++;
			}
			map_chars_check(map_info, map_info->map[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
	if (map_info->exits != 1)
		print_error("numero incorrecto de salidas en el mapa.", map_info);
	if (map_info->players != 1)
		print_error("numero incorrecto de players en el mapa.", map_info);
}

void	save_map(t_map_info *map_info)
{
	char	*new_line;
	int		i;
	int		j;

	i = 1;
	j = 0;
	new_line = get_next_line(map_info->fd);
	if (!new_line)
		print_error("error, mapa vacio.", map_info);
	map_info->x_size = ft_strlen(new_line);
	map_info->map[0] = new_line;
	while (new_line != NULL)
	{
		new_line = get_next_line(map_info->fd);
		map_info->map[i] = new_line;
		if (new_line && ft_strlen(new_line) != (unsigned long)map_info->x_size)
		{
			map_info->map[i + 1] = NULL;
			print_error("el mapa no es rectangular.", map_info);
		}
		i++;
	}
	map_info->map[i] = NULL;
	while (map_info->map[j])
		map_info->y_size = ++j;
}

void	check_map(int argc, char **argv, t_map_info *map_info)
{
	if (argc != 2)
		print_error("numero incorrecto de parametros.", map_info);
	map_info->fd = open(argv[1], 0);
	if (map_info->fd < 1)
		print_error("fallo al abrir fichero.", map_info);
	save_map(map_info);
	map_matcheck(map_info);
	if (check_extwalls(map_info) == 0)
		print_error("paredes exteriores incompletas.", map_info);
	check_floodfill(map_info);
}
