/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:38:01 by jeperez-          #+#    #+#             */
/*   Updated: 2025/05/02 10:52:56 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	move_player_y(t_cub3d *cub, t_vector mv_dir)
{
	t_vector	*p_pos;
	t_vector	*p_dir;
	t_vector	new_pos;

	p_pos = &cub->map.player.pos;
	p_dir = &cub->map.player.dir;
	if (mv_dir.y < 0)
	{
		new_pos = *p_pos;
		new_pos.x -= (MV_SPD / (fabs(mv_dir.x) + fabs(mv_dir.y))) * p_dir->y;
		new_pos.y += (MV_SPD / (fabs(mv_dir.x) + fabs(mv_dir.y))) * p_dir->x;
		if (cub->map.map[(int)new_pos.x][(int)new_pos.y] == '0')
			*p_pos = new_pos;
	}
	else if (mv_dir.y > 0)
	{
		new_pos = *p_pos;
		new_pos.x += (MV_SPD / (fabs(mv_dir.x) + fabs(mv_dir.y))) * p_dir->y;
		new_pos.y -= (MV_SPD / (fabs(mv_dir.x) + fabs(mv_dir.y))) * p_dir->x;
		if (cub->map.map[(int)new_pos.x][(int)new_pos.y] == '0')
			*p_pos = new_pos;
	}
}

static void	move_player_x(t_cub3d *cub, t_vector mv_dir)
{
	t_vector	*p_pos;
	t_vector	*p_dir;
	t_vector	new_pos;

	p_pos = &cub->map.player.pos;
	p_dir = &cub->map.player.dir;
	if (mv_dir.x > 0)
	{
		new_pos = *p_pos;
		new_pos.x += (MV_SPD / (fabs(mv_dir.x) + fabs(mv_dir.y))) * p_dir->x;
		new_pos.y += (MV_SPD / (fabs(mv_dir.x) + fabs(mv_dir.y))) * p_dir->y;
		if (cub->map.map[(int)new_pos.x][(int)new_pos.y] == '0')
			*p_pos = new_pos;
	}
	else if (mv_dir.x < 0)
	{
		new_pos = *p_pos;
		new_pos.x -= (MV_SPD / (fabs(mv_dir.x) + fabs(mv_dir.y))) * p_dir->x;
		new_pos.y -= (MV_SPD / (fabs(mv_dir.x) + fabs(mv_dir.y))) * p_dir->y;
		if (cub->map.map[(int)new_pos.x][(int)new_pos.y] == '0')
		{
			*p_pos = new_pos;
		}
	}
}

static void	turn_player(t_cub3d *cub, int tn_dir)
{
	t_vector	new_dir;
	t_vector	new_plane;
	t_player	*p;

	if (tn_dir == 0)
		return ;
	p = &cub->map.player;
	if (tn_dir > 0)
	{
		new_dir.x = p->dir.x * cos(TN_SPD) - p->dir.y * sin (TN_SPD);
		new_dir.y = p->dir.x * sin(TN_SPD) + p->dir.y * cos(TN_SPD);
		new_plane.x = p->plane.x * cos(TN_SPD) - p->plane.y * sin(TN_SPD);
		new_plane.y = p->plane.x * sin(TN_SPD) + p->plane.y * cos(TN_SPD);
	}
	else
	{
		new_dir.x = p->dir.x * cos(-TN_SPD) - p->dir.y * sin (-TN_SPD);
		new_dir.y = p->dir.x * sin(-TN_SPD) + p->dir.y * cos(-TN_SPD);
		new_plane.x = p->plane.x * cos(-TN_SPD) - p->plane.y * sin(-TN_SPD);
		new_plane.y = p->plane.x * sin(-TN_SPD) + p->plane.y * cos(-TN_SPD);
	}
	p->dir = new_dir;
	p->plane = new_plane;
}

static void	key_handler(t_cub3d *cub)
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

void	loop_hook(void *param)
{
	key_handler(param);
}
