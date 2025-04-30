/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:09:54 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/30 13:08:15 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42.h"
# include "libft.h"
# include "vector.h"

typedef uint32_t	t_color;

typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
}				t_player;

typedef struct s_map
{
	mlx_texture_t	*texture[4];
	t_color			floor;
	t_color			ceil;
	char			**map;
	t_player		player;
}					t_map;

typedef struct s_cub3d
{
	t_map	map;
	mlx_t	*mlx;
}			t_cub3d;

void	parse_file(t_map *map, char *filepath);

#endif
