/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvasanc <alvasanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:43:29 by alvasanc          #+#    #+#             */
/*   Updated: 2024/02/06 12:06:31 by alvasanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	flood_fill(t_map_info *map_info, int x, int y)
{
	if (map_info->ff_map[y][x] == '1')
		return ;
	if (map_info->ff_map[y][x] == 'C')
		map_info->ff_collec++;
	if (map_info->ff_map[y][x] == 'E')
		map_info->ff_exits++;
	map_info->ff_map[y][x] = '1';
	flood_fill(map_info, x, y - 1);
	flood_fill(map_info, x, y + 1);
	flood_fill(map_info, x - 1, y);
	flood_fill(map_info, x + 1, y);
}

void	check_floodfill(t_map_info *map_info)
{
	int	i;

	i = 0;
	map_info->ff_map = matdup(map_info->map);
	flood_fill(map_info, map_info->p_pos_x, map_info->p_pos_y);
	if (map_info->collectables != map_info->ff_collec)
		print_error("No son accesibles todos los colecionables.", map_info);
	if (map_info->ff_exits != map_info->exits)
		print_error("La salida no es accesible.", map_info);
}
