/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvasanc <alvasanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:13:30 by alvasanc          #+#    #+#             */
/*   Updated: 2024/03/05 11:07:55 by alvasanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map_textures(t_map_info *map_info)
{
	if (map_info->stone_t)
		mlx_delete_texture(map_info->stone_t);
	if (map_info->ground_t)
		mlx_delete_texture(map_info->ground_t);
	if (map_info->exit_t)
		mlx_delete_texture(map_info->exit_t);
}

void	free_items_texture(t_map_info *map_info)
{
	if (map_info->coin_t)
		mlx_delete_texture(map_info->coin_t);
	if (map_info->player_t)
		mlx_delete_texture(map_info->player_t);
}

void	free_all(t_map_info *map_info)
{
	if (map_info)
	{
		if (map_info->map)
			free_mat(map_info->map);
		if (map_info->ff_map)
			free_mat(map_info->ff_map);
		free_map_textures(map_info);
		free_items_texture(map_info);
		if (map_info->mlx)
			mlx_terminate(map_info->mlx);
		close (map_info->fd);
		free(map_info);
	}
}
