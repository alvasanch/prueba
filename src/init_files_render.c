/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_files_render.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvasanc <alvasanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:29:38 by alvasanc          #+#    #+#             */
/*   Updated: 2024/02/14 11:11:58 by alvasanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_tenemy_imgs(t_tenemy_rend *tenemy_r, mlx_t *mlx, t_map_info *m_i)
{
	if (!(tenemy_r->tenemy_01_t))
	{
		tenemy_r->tenemy_01_t = mlx_load_png("");
		// tenemy_r->tenemy_02_t = mlx_load_png("");
		// tenemy_r->tenemy_03_t = mlx_load_png("");
		// tenemy_r->tenemy_04_t = mlx_load_png("");
	}
	if (!(tenemy_r->tenemy_01_t))
	 	// || !(tenemy_r->tenemy_02_t)	|| !(tenemy_r->tenemy_03_t) || !(tenemy_r->tenemy_04_t))
		print_error("fallo al iniciar texturas de enemigo.", m_i);
	tenemy_r->tenemy_01 = mlx_texture_to_image(mlx, tenemy_r->tenemy_01_t);
	// tenemy_r->tenemy_02 = mlx_texture_to_image(mlx, tenemy_r->tenemy_02_t);
	// tenemy_r->tenemy_03 = mlx_texture_to_image(mlx, tenemy_r->tenemy_03_t);
	// tenemy_r->tenemy_04 = mlx_texture_to_image(mlx, tenemy_r->tenemy_04_t);
	if (!(tenemy_r->tenemy_01))
	// || !(tenemy_r->tenemy_02)|| !(tenemy_r->tenemy_03) || !(tenemy_r->tenemy_04))
		print_error("fallo al iniciar imagen de enemigo.", m_i);
}

void	new_tenemy_render(t_map_info *map_info)
{
	t_tenemy_rend	*tenemy_render;

	tenemy_render = ft_calloc(1, sizeof(t_tenemy_rend));
	if (!tenemy_render)
		print_error("fallo de asignacion de memoria.", map_info);
	map_info->tenemy_r = tenemy_render;
	map_info->tenemy_r->tenemy_01 = NULL;
	// map_info->tenemy_r->tenemy_02 = NULL;
	// map_info->tenemy_r->tenemy_03 = NULL;
	// map_info->tenemy_r->tenemy_04 = NULL;
	map_info->tenemy_r->tenemy_01_t = NULL;
	// map_info->tenemy_r->tenemy_02_t = NULL;
	// map_info->tenemy_r->tenemy_03_t = NULL;
	// map_info->tenemy_r->tenemy_04_t = NULL;
	map_info->tenemy_r->x = 0;
	map_info->tenemy_r->y = 0;
}

void	render_flies_onmap(t_map_info *m, t_tenemy_rend *t)
{
	if (m->tflies == 1)
	{
		if ((mlx_image_to_window(m->mlx, t->tfly_01, t->x * 64, t->y * 64) < 0))
			print_error("error en renderizado de imagen de enemigo.", m);
		// if ((mlx_image_to_window(m->mlx, t->tfly_02, t->x * 64, t->y * 64) < 0))
		// 	print_error("problem rendering the tfly_02 image.", m);
		// if ((mlx_image_to_window(m->mlx, t->tfly_03, t->x * 64, t->y * 64) < 0))
		// 	print_error("problem rendering the tfly_03 image.", m);
		// if ((mlx_image_to_window(m->mlx, t->tfly_04, t->x * 64, t->y * 64) < 0))
		// 	print_error("problem rendering the tfly_04 image.", m);
	}
}
