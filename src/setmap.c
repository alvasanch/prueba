/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvasanc <alvasanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:05:39 by alvasanc          #+#    #+#             */
/*   Updated: 2024/02/14 12:31:29 by alvasanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_player_t(t_map_info *map_info)
{
	mlx_texture_t	*player_t;
	mlx_image_t		*player;
	int				pos_y;
	int				pos_x;
	char			*path;

	path = NULL;
	path = create_path(map_info, "", path);
	player_t = mlx_load_png(path);
	free (path);
	player = mlx_texture_to_image(map_info->mlx, player_t);
	pos_y = map_info->p_pos_y * 64;
	pos_x = map_info->p_pos_x * 64;
	if (!player || (mlx_image_to_window(map_info->mlx, player, pos_x,
				pos_y) < 0))
		print_error("error al crear player.", map_info);
	map_info->player_t = player_t;
	map_info->player = player;
}

mlx_image_t	*check_walls_spr(t_map_info *map_info, char content, int y, int x)
{
	int	x_size;
	int	y_size;

	x_size = map_info->x_size;
	y_size = map_info->y_size;
	if (content == '1' && y == 0 && x == 0)
		return (map_info->corner_tl);
	else if (content == '1' && y == 0 && x == (x_size - 1))
		return (map_info->corner_tr);
	else if (content == '1' && y == (y_size - 1) && x == 0)
		return (map_info->corner_bl);
	else if (content == '1' && y == (y_size - 1) && x == (x_size - 1))
		return (map_info->corner_br);
	else if (content == '1' && y == 0)
		return (map_info->t_wall);
	else if (content == '1' && x == 0)
		return (map_info->l_wall);
	else if (content == '1' && y == (y_size - 1))
		return (map_info->b_wall);
	else if (content == '1' && x == (x_size - 1))
		return (map_info->r_wall);
	return (NULL);
}

mlx_image_t	*check_sprites(t_map_info *map_info, int y, int x)
{
	mlx_image_t	*return_value;

	return_value = check_walls_spr(map_info, map_info->map[y][x], y, x);
	if (return_value)
		return (return_value);
	if (map_info->map[y][x] == '1')
		return (map_info->stone);
	else if (map_info->map[y][x] == '0' || map_info->map[y][x] == 'P')
		return (map_info->ground);
	else if (map_info->map[y][x] == 'C')
	{
		if (mlx_image_to_window(map_info->mlx, map_info->ground, x * 64, y
				* 64) < 0)
			print_error("no se renderiza suelo tras coleccionable.", map_info);
		return (map_info->coin);
	}
	else if (map_info->map[y][x] == 'E')
		return (map_info->exit);
	return (NULL);
}

void	set_tiles(t_map_info *map_info)
{
	mlx_image_t	*img;
	mlx_t		*mlx;
	int			y;
	int			x;

	mlx = map_info->mlx;
	y = 0;
	while (y < map_info->y_size)
	{
		x = 0;
		while (x < map_info->x_size)
		{
			img = check_sprites(map_info, y, x);
			if (mlx_image_to_window(mlx, img, (x++) * 64, y * 64) < 0)
				print_error("error renderizado de imagen", map_info);
			if (map_info->map[y][x - 1] == 'E')
				if (mlx_image_to_window(map_info->mlx, map_info->c_exit, (x - 1)
						* 64, y * 64) < 0)
					print_error("error renderizado de salida.", map_info);
		}
		y++;
	}
	set_player_t(map_info);
}
