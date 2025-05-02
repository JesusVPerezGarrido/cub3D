/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 10:07:29 by jeperez-          #+#    #+#             */
/*   Updated: 2025/05/02 10:09:40 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_pixel(mlx_image_t *img, int x, int y, t_color c)
{
	if (x < 0 || y < 0 || x > (int)img->width - 1 || y > (int)img->height - 1)
		return ;
	mlx_put_pixel(img, x, y, c);
}

t_color	get_tex_color(int x, int y, mlx_texture_t *t)
{
	t_color	c;
	int		pos;
	int		i;

	if ( x < 0 || y < 0 || x > (int)t->width - 1 || y > (int)t->height - 1)
		return (0);
	pos = (t->width * y + x) * t->bytes_per_pixel;
	c = 0;
	i = 0;
	while (i < t->bytes_per_pixel)
	{	
		c = c << 8;
		c += t->pixels[pos + i];
		i++;
	}
	return (c);
}

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
