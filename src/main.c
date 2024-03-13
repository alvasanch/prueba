/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvasanc <alvasanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:45:02 by alvasanc          #+#    #+#             */
/*   Updated: 2024/03/11 11:38:04 by alvasanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	initialize_textures(t_map_info *map_info)
{
	map_info->stone_t = NULL;
	map_info->ground_t = NULL;
	map_info->coin_t = NULL;
	map_info->exit_t = NULL;
	map_info->player_t = NULL;
}

t_map_info	*new_map_info(void)
{
	t_map_info	*map_info;

	map_info = malloc(sizeof(t_map_info));
	if (!map_info)
		return (NULL);
	map_info->collectables = 0;
	map_info->exits = 0;
	map_info->players = 0;
	map_info->x_size = 0;
	map_info->y_size = 0;
	map_info->map = malloc(sizeof(char *) * 100);
	if (!(map_info->map))
		print_error("error asignacion de memoria(map_info->map)", map_info);
	map_info->p_pos_x = 0;
	map_info->p_pos_y = 0;
	map_info->ff_collec = 0;
	map_info->ff_exits = 0;
	map_info->ff_map = NULL;
	map_info->fd = 0;
	map_info->steps = 0;
	map_info->mlx = NULL;
	initialize_textures(map_info);
	return (map_info);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_map_info	*m_i;

	m_i = param;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		check_move(m_i, 1, m_i->p_pos_y - 1, m_i->p_pos_x);
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		check_move(m_i, 2, m_i->p_pos_y, m_i->p_pos_x + 1);
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		check_move(m_i, 3, m_i->p_pos_y + 1, m_i->p_pos_x);
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		check_move(m_i, 4, m_i->p_pos_y, m_i->p_pos_x - 1);
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		free_all(m_i);
		exit (0);
	}
}

int	main(int argc, char **argv)
{
	t_map_info		*map_info;

	map_info = new_map_info();
	if (!map_info)
		print_error("fallo asignacion de memoria(map_info)", map_info);
	check_map(argc, argv, map_info);
	load_textures_imgs(map_info);
	set_tiles(map_info);
	mlx_key_hook(map_info->mlx, &my_keyhook, map_info);
	mlx_loop(map_info->mlx);
	return (0);
}
