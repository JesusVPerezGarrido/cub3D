/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:09:54 by jeperez-          #+#    #+#             */
/*   Updated: 2025/05/01 10:28:16 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define MV_SPD 0.1
# define TN_SPD 0.05

# include "MLX42.h"
# include "libft.h"
# include "vector.h"
# include "color.h"
# include "raycast.h"

typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
}				t_player;

typedef struct s_map
{
	mlx_texture_t	*texture[4];
	t_color			floor;
	t_color			ceil;
	int				height;
	int				width;
	char			**map;
	t_player		player;
}					t_map;

typedef struct s_cub3d
{
	t_map		map;
	mlx_t		*mlx;
	mlx_image_t	*background;
	mlx_image_t	*walls;
}				t_cub3d;

void	parse_file(t_map *map, char *filepath);
void	cub_start(t_cub3d *cub);
void	draw_square(mlx_image_t *img, t_vector start, t_vector end, t_color c);
void	loop_hook(void *param);
void	draw_frame(t_cub3d *cub);
#endif
