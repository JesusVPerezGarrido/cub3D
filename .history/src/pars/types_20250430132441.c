/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:54:16 by auloth            #+#    #+#             */
/*   Updated: 2025/04/30 13:24:41 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int empty_line(char *line)
{
	int i;

	i = 0;
	while(line[i] )
}

set_type(t_map *map, char** line, int c)
{
	if(ft_strncmp(&line[c], "NA", 2))
		map->texture[0] = mlx_load_png(line[c + 2]);
	if(ft_strncmp(&line[c], "SO", 2))
		map->texture[1] = mlx_load_png(line[c + 2]);
	if(ft_strncmp(&line[c], "WE", 2))
		map->texture[2] = mlx_load_png(line[c + 2]);
	if(ft_strncmp(&line[c], "EA", 2))
		map->texture[3] = mlx_load_png(line[c + 2]);
}

parse_line(t_map *map, char *line)
{
	int i;

	i = 0;
	while(line[i] == ' ')
		i++;
	set_type(map, ft_split(line, ' '), i);
}
