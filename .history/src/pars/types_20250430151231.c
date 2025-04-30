/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:54:16 by auloth            #+#    #+#             */
/*   Updated: 2025/04/30 15:12:31 by auloth           ###   ########.fr       */
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

int set_type(t_map *map, char** l)
{
	if(ft_strncmp(l[0], "NA", 2))
		return (map->texture[0] = mlx_load_png(l[1]), free_matrix(l), 1);
	if(ft_strncmp(l[0], "SO", 2))
		return (map->texture[1] = mlx_load_png(l[1]), free_matrix(l), 1);
	if(ft_strncmp(l[0], "WE", 2))
		return (map->texture[2] = mlx_load_png(l[1]), free_matrix(l), 1);
	if(ft_strncmp(l[0], "EA", 2))
		return (map->texture[3] = mlx_load_png(l[1]), free_matrix(l), 1);
	if(ft_strncmp(l[0], "F ", 1))
		return (map->floor = co_split(ft_split(l[1], ',')), free_matrix(l), 1);
	if(ft_strncmp(l[0], "C ", 1))
		return (map->ceil = co_split(ft_split(l[1], ',')), free_matrix(l), 1);
	return(free(l), 0);
}

void parse_line(t_map *map, char *line)
{
	if(empty_line(line))
		return;

	if (full())
	set_type(map, ft_split(line, ' '))
}
