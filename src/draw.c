/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:25:44 by jeperez-          #+#    #+#             */
/*   Updated: 2025/05/01 10:30:35 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_square(mlx_image_t *img, t_vector start, t_vector end, t_color c)
{
	int	x;
	int	y;

	x = start.x;
	while (x < end.x)
	{
		y = start.y;
		while (y < end.y)
		{
			mlx_put_pixel(img, x, y, c);
			y++;
		}
		x++;
	}
}

void	draw_ray(mlx_image_t *img, int x, t_raycast ray, t_map map)
{
	int	line_height;
	int	draw_start;
	int	draw_end;
	int	y;

	(void)map;
	line_height = SCREEN_HEIGHT / ray.wall_dist;
	draw_start = ft_highest(-line_height / 2 + SCREEN_HEIGHT / 2, 0);
	draw_end = ft_lowest(line_height / 2 + SCREEN_HEIGHT / 2, SCREEN_HEIGHT - 1);
	y = draw_start;
	while (y < draw_end)
	{
		mlx_put_pixel(img, x, y, 0xFFFFFFFF);
		y++;
	}
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
