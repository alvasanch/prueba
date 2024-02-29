/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvasanc <alvasanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:25:46 by alvasanc          #+#    #+#             */
/*   Updated: 2024/02/29 12:10:46 by alvasanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define HEIGHT 512
# define WIDTH 512
# include "lib/MLX42/include/MLX42/MLX42.h"
# include "lib/libft+gnl+printf/libft.h"

typedef struct t_map_information
{
	int				collectables;
	int				players;
	int				exits;
	int				x_size;
	int				y_size;
	char			**map;
	int				p_pos_x;
	int				p_pos_y;
	int				ff_collec;
	int				ff_exits;
	char			**ff_map;
	int				fd;
	int				steps;
	mlx_t			*mlx;
	mlx_image_t		*stone;
	mlx_image_t		*ground;
	mlx_image_t		*coin;
	mlx_image_t		*exit;
	mlx_image_t		*player;
	mlx_texture_t	*stone_t;
	mlx_texture_t	*ground_t;
	mlx_texture_t	*coin_t;
	mlx_texture_t	*exit_t;
	mlx_texture_t	*player_t;
	//añadir las variables de los enemigos tanto textura como img
}							t_map_info;

void		check_map(int argc, char **argv, t_map_info *map_info);
void		print_error(char *errormsg, t_map_info *map_info);
t_map_info	*new_map_info(void);
void		check_floodfill(t_map_info *map_info);
void		free_mat(char **mat);
char		**matdup(char **mat);
void		set_tiles(t_map_info *map_info);
void		load_textures_imgs(t_map_info *map_info);
void		check_move(t_map_info *map_info, int direction, int y, int x);
void		set_player_t(t_map_info *map_info);
void		reload_player(t_map_info *map_info);
void		free_all(t_map_info *map_info);
int			check_move_b(t_map_info *map_info, int direction, int y, int x);

#endif