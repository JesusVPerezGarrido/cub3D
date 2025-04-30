/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:54:16 by auloth            #+#    #+#             */
/*   Updated: 2025/04/30 14:04:47 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"



int empty_line(char *line)
{
	int i;

	i = 0;
	while(line[i] != 0)
	{
		if(line[i] != ' ' && line[i] != '\n')
			return(1);
		i++;
	}
	return(0);
}

int set_type(t_map *map, char** line)
{
	if(ft_strncmp(line[0], "NA", 2))
		return (map->texture[0] = mlx_load_png(line[1]), 1);
	if(ft_strncmp(line[0], "SO", 2))
		return (map->texture[1] = mlx_load_png(line[1]), 1);
	if(ft_strncmp(line[0], "WE", 2))
		map->texture[2] = mlx_load_png(line[1]);
	if(ft_strncmp(line[0], "EA", 2))
		map->texture[3] = mlx_load_png(line[1]);
	if(ft_strncmp(line[0], "F ", 1))
		map->floor = color_spliter(ft_split(line[1], ','));
	if(ft_strncmp(line[0], "C ", 1))
		map->ceil = color_spliter(ft_split(line[1], ','));
}

void parse_line(t_map *map, char *line)
{
	if(empty_line(line))
		return;
	set_type(map, ft_split(line, ' '));
}
