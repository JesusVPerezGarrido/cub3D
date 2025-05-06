/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:24:16 by jeperez-          #+#    #+#             */
/*   Updated: 2025/05/06 15:46:45 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

double	ft_lowestd(double d1, double d2)
{
	if (d1 < d2)
		return (d1);
	return (d2);
}

static void	raycast_init_direction(t_raycast *ray)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (ray->pos.x - (int)ray->pos.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = ((int)ray->pos.x + 1 - ray->pos.x);
		ray->side_dist.x *= ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (ray->pos.y - (int)ray->pos.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = ((int)ray->pos.y + 1.0 - ray->pos.y);
		ray->side_dist.y *= ray->delta_dist.y;
	}
}

t_raycast	raycast_init(t_vector init_pos, t_vector direction)
{
	t_raycast	value;

	value.pos = init_pos;
	value.dir = direction;
	value.delta_dist = set_vector(fabs(1 / value.dir.x), fabs(1 / value.dir.y));
	raycast_init_direction(&value);
	value.hit = 0;
	value.side = -1;
	return (value);
}

void	raycast_loop(t_raycast *ray, char **world_map)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->pos.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->pos.y += ray->step.y;
			ray->side = 1;
		}
		if (world_map[(int)ray->pos.x][(int)ray->pos.y] != '0')
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->wall_dist = ray->side_dist.x - ray->delta_dist.x;
	else
		ray->wall_dist = ray->side_dist.y - ray->delta_dist.y;
}
