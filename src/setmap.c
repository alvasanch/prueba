/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvasanc <alvasanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:05:39 by alvasanc          #+#    #+#             */
/*   Updated: 2024/02/29 12:27:28 by alvasanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_player_t(t_map_info *map_info)
{
	mlx_texture_t	*player_t;
	mlx_image_t		*player;
	int				pos_y;
	int				pos_x;

	player_t = mlx_load_png("./sprites/void.png");
	player = mlx_texture_to_image(map_info->mlx, player_t);
	pos_y = map_info->p_pos_y * 64;
	pos_x = map_info->p_pos_x * 64;
	if (!player || (mlx_image_to_window(map_info->mlx, player, pos_x,
				pos_y) < 0))
		print_error("error al crear player.", map_info);
	map_info->player_t = player_t;
	map_info->player = player;
}

mlx_image_t	*check_sprites(t_map_info *map_info, int y, int x)
{
	//añadir el "devolver" las imágenes de los enemigos cuando te encuentres sus letras correspondientes en el mapa
	if (map_info->map[y][x] == '1')
		return (map_info->stone);
	if (map_info->map[y][x] == '0' || map_info->map[y][x] == 'P')
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
/* int i;

i = 0;
if (mlx->hades_t_brillante->instance[0].enabled == true)
{
	while (i < enemies)
	{
		mlx->hades_brillante->instance[i].enabled == false;
		mlx->hades_apagao->instance[i].enabled == true;
	}
}
else if (mlx->hades_apagado->instance[0].enabled == true)
{
	while (i < enemies)
	{
		mlx->hades_apagao->instance[i].enabled == false;
		mlx->hades_brillante->instance[i].enabled == true;
	}
} */

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
		}
		y++;
	}
	set_player_t(map_info);
}
