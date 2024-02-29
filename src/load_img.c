/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvasanc <alvasanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:29:39 by alvasanc          #+#    #+#             */
/*   Updated: 2024/02/29 12:09:38 by alvasanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_textures_imgs(t_map_info *m_i)
{
	//añadir tanto la carga de la text como de la img por cada tipo de enemigo
	m_i->mlx = mlx_init(m_i->x_size * 64, m_i->y_size * 64, "Window", false);
	m_i->stone_t = mlx_load_png("./sprites/pared.png");
	m_i->ground_t = mlx_load_png("./sprites/suelo.png");
	m_i->coin_t = mlx_load_png("./sprites/coleccionable.png");
	m_i->exit_t = mlx_load_png("./sprites/salida.png");
	if (!(m_i->stone_t) || !(m_i->ground_t) || !(m_i->coin_t) || !(m_i->exit_t))
		print_error("error al crear texturas", m_i);
	m_i->stone = mlx_texture_to_image(m_i->mlx, m_i->stone_t);
	m_i->ground = mlx_texture_to_image(m_i->mlx, m_i->ground_t);
	m_i->coin = mlx_texture_to_image(m_i->mlx, m_i->coin_t);
	m_i->exit = mlx_texture_to_image(m_i->mlx, m_i->exit_t);
	if (!(m_i->exit) || !(m_i->mlx) || !(m_i->stone) || !(m_i->ground)
		|| !(m_i->coin))
		print_error("error al crear imágenes.", m_i);
}

void	reload_player(t_map_info *m_i)
{
	mlx_delete_texture(m_i->player_t);
	mlx_delete_image(m_i->mlx, m_i->player);
	set_player_t(m_i);
}
