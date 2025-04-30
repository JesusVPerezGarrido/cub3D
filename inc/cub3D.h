/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:09:54 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/30 11:22:05 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42.h"
# include "libft.h"
# include "vector.h"

typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
}				t_player;

typedef struct s_map
{
	mlx_texture_t	*texture[4];
	int				height;
	int				width;
	char			*map;
	t_player		player;
}					t_map;

typedef struct s_cub3d
{
	t_map	map;
	mlx_t	*mlx;
}			t_cub3d;

void	parse_map(t_map *map, char *filepath);

#endif
