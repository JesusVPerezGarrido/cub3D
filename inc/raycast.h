/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:24:07 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/30 16:03:32 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include <math.h>
# include "angles.h"
# include "vector.h"

# include <stdio.h>

typedef struct s_raycast
{
	t_vector	pos;
	t_vector	dir;
	t_vector	side_dist;
	t_vector	delta_dist;
	double		wall_dist;
	t_vector	step;
	int			hit;
	int			side;
}	t_raycast;

t_raycast	raycast_init(t_vector init_pos, t_vector direction);
void		raycast_loop(t_raycast *ray, char **world_map);

#endif
