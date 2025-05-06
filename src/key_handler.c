/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:48:06 by jeperez-          #+#    #+#             */
/*   Updated: 2025/05/06 11:22:08 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_wall(t_vector start, t_vector end, t_map map)
{
	t_vector	mv;

	mv = set_vector(end.x - start.x, end.y - start.y);
	if (map.map[(int)start.x][(int)start.y] != '0')
		return (0);
	if (map.map[(int)(start.x + mv.x)][(int)start.y] != '0')
		return (0);
	if (map.map[(int)start.x][(int)(start.y + mv.y)] != '0')
		return (0);
	if (map.map[(int)(start.x + mv.x)][(int)(start.y + mv.y)] != '0')
		return (0);
	return (1);
}

static void	move_player_y(t_cub3d *cub, t_vector mv_dir)
{
	t_vector	*p_pos;
	t_vector	*p_dir;
	t_vector	new_pos;
	double		dist;

	if (!mv_dir.y)
		return ;
	dist = cub->mlx->delta_time * MV_SPD / (fabs(mv_dir.x) + fabs(mv_dir.y));
	p_pos = &cub->map.player.pos;
	p_dir = &cub->map.player.dir;
	new_pos = *p_pos;
	new_pos.x += mv_dir.y * dist * p_dir->y;
	if (check_wall(*p_pos, new_pos, cub->map) == 1)
		*p_pos = new_pos;
	new_pos = *p_pos;
	new_pos.y += -mv_dir.y * dist * p_dir->x;
	if (check_wall(*p_pos, new_pos, cub->map) == 1)
		*p_pos = new_pos;
}

static void	move_player_x(t_cub3d *cub, t_vector mv_dir)
{
	t_vector	*p_pos;
	t_vector	*p_dir;
	t_vector	new_pos;
	double		dist;

	if (!mv_dir.x)
		return ;
	dist = cub->mlx->delta_time * MV_SPD / (fabs(mv_dir.x) + fabs(mv_dir.y));
	p_pos = &cub->map.player.pos;
	p_dir = &cub->map.player.dir;
	new_pos = *p_pos;
	new_pos.x += mv_dir.x * dist * p_dir->x;
	if (check_wall(*p_pos, new_pos, cub->map) == 1)
		*p_pos = new_pos;
	new_pos = *p_pos;
	new_pos.y += mv_dir.x * dist * p_dir->y;
	if (check_wall(*p_pos, new_pos, cub->map) == 1)
		*p_pos = new_pos;
}

static void	turn_player(t_cub3d *cub, int tn_dir)
{
	t_vector	new_dir;
	t_vector	new_plane;
	t_player	*p;
	double		dist;

	if (tn_dir == 0)
		return ;
	dist = cub->mlx->delta_time * TN_SPD;
	p = &cub->map.player;
	if (tn_dir > 0)
	{
		new_dir.x = p->dir.x * cos(dist) - p->dir.y * sin (dist);
		new_dir.y = p->dir.x * sin(dist) + p->dir.y * cos(dist);
		new_plane.x = p->plane.x * cos(dist) - p->plane.y * sin(dist);
		new_plane.y = p->plane.x * sin(dist) + p->plane.y * cos(dist);
	}
	else
	{
		new_dir.x = p->dir.x * cos(-dist) - p->dir.y * sin (-dist);
		new_dir.y = p->dir.x * sin(-dist) + p->dir.y * cos(-dist);
		new_plane.x = p->plane.x * cos(-dist) - p->plane.y * sin(-dist);
		new_plane.y = p->plane.x * sin(-dist) + p->plane.y * cos(-dist);
	}
	p->dir = new_dir;
	p->plane = new_plane;
}

void	key_handler(t_cub3d *cub)
{
	t_vector	move_dir;
	int			turn_dir;

	move_dir = set_vector(0, 0);
	turn_dir = 0;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_ESCAPE))
		exit(1);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_W))
		move_dir.x += 1;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_S))
		move_dir.x -= 1;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_A))
		move_dir.y -= 1;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_D))
		move_dir.y += 1;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_LEFT))
		turn_dir += 1;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_RIGHT))
		turn_dir -= 1;
	move_player_x(cub, move_dir);
	move_player_y(cub, move_dir);
	turn_player(cub, turn_dir);
	if (move_dir.x || move_dir.y || turn_dir)
		draw_frame(cub);
}
