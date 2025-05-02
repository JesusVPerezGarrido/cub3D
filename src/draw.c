/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:25:44 by jeperez-          #+#    #+#             */
/*   Updated: 2025/05/02 10:48:06 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_vector	get_draw_length(t_raycast ray)
{
	int			line_height;
	t_vector	draw;

	line_height = (int)(SCREEN_HEIGHT / ray.wall_dist);
	draw.x = (SCREEN_HEIGHT - line_height) / 2;
	draw.y = (line_height + SCREEN_HEIGHT) / 2;
	return (draw);
}

double	get_wall_x(t_raycast ray, mlx_texture_t *t)
{
	double	wallx;
	int		tx;

	if (ray.side == 0)
		wallx = ray.pos.y + ray.wall_dist * ray.dir.y;
	else
		wallx = ray.pos.x + ray.wall_dist * ray.dir.x;
	wallx -= (int)wallx;
	tx = (int)(wallx * t->width);
	if (ray.side == 0 && ray.dir.x > 0)
		tx = t->width - tx - 1;
	if (ray.side == 1 && ray.dir.y < 0)
		tx = t->width - tx - 1;
	return (tx % t->width);
}

void	draw_wall(mlx_image_t *img, int x, t_raycast ray, mlx_texture_t *t)
{
	int			y;
	t_vector	tpos;
	t_vector	length;
	t_color		c;

	length = get_draw_length(ray);
	tpos.x = get_wall_x(ray, t);
	y = ft_highest(length.x, 0);
	while (y < ft_lowest(length.y, SCREEN_HEIGHT - 1))
	{
		tpos.y = (y - length.x) / (length.y - length.x) * t->height;
		c = get_tex_color(tpos.x, tpos.y, t);
		draw_pixel(img, x, y, c);
		y++;
	}
}

void	draw_ray(mlx_image_t *img, int x, t_raycast ray, t_map map)
{
	mlx_texture_t	*t;

	if (ray.side == 0)
	{
		if (ray.dir.x > 0)
			t = map.texture[0];
		else
			t = map.texture[1];
	}
	else
	{
		if (ray.dir.y > 0)
			t = map.texture[2];
		else
			t = map.texture[3];
	}
	draw_wall(img, x, ray, t);
}

void	draw_frame(t_cub3d *cub)
{
	mlx_image_t	*img;
	int			index;
	double		camera_x;
	t_raycast	ray;
	t_vector	ray_dir;

	img = mlx_new_image(cub->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	index = 0;
	while (index < SCREEN_WIDTH)
	{
		camera_x = 2 * index / (double)SCREEN_WIDTH - 1;
		ray_dir.x = cub->map.player.dir.x + cub->map.player.plane.x * camera_x;
		ray_dir.y = cub->map.player.dir.y + cub->map.player.plane.y * camera_x;
		ray = raycast_init(cub->map.player.pos, ray_dir);
		raycast_loop(&ray, cub->map.map);
		draw_ray(img, index, ray, cub->map);
		index++;
	}
	mlx_image_to_window(cub->mlx, img, 0, 0);
	if (cub->walls)
		mlx_delete_image(cub->mlx, cub->walls);
	cub->walls = img;
}
