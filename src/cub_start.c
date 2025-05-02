/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:14:37 by jeperez-          #+#    #+#             */
/*   Updated: 2025/05/02 10:24:11 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	create_background(t_cub3d *cub)
{
	cub->background = mlx_new_image(cub->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!cub->background)
	{
		ft_printf("mlx error\n");
		exit(1);
	}
	draw_square(cub->background,
		set_vector(0, 0),
		set_vector(SCREEN_WIDTH - 1, (SCREEN_HEIGHT / 2) - 1),
		cub->map.ceil);
	draw_square(cub->background,
		set_vector(0, SCREEN_HEIGHT / 2),
		set_vector(SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1),
		cub->map.floor);
	mlx_image_to_window(cub->mlx, cub->background, 0, 0);
}

void	mlx_start(t_cub3d *cub)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	cub->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D", true);
	if (!cub->mlx)
	{
		ft_printf("mlx error\n");
		exit(1);
	}
	create_background(cub);
	mlx_loop_hook(cub->mlx, loop_hook, cub);
	draw_frame(cub);
}

void	cub_start(t_cub3d *cub)
{
	mlx_start(cub);
	mlx_loop(cub->mlx);
}
