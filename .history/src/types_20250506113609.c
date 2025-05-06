/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:54:16 by auloth            #+#    #+#             */
/*   Updated: 2025/05/06 11:36:09 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	full(t_map *map)
{
	if (map->ceil == 0)
		return (0);
	if (map->floor == 0)
		return (0);
	if (map->texture[0] == NULL)
		return (0);
	if (map->texture[1] == NULL)
		return (0);
	if (map->texture[2] == NULL)
		return (0);
	if (map->texture[3] == NULL)
		return (0);
	return (1);
}

int	empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != 0)
	{
		if (line[i] != ' ' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	set_type(t_map *map, char **l, char *line)
{
	free(line);
	if (ft_strncmp(l[0], "NO", 2) == 0)
		return (map->texture[0] = mlx_load_png(l[1]), free_matrix((void **)l),
			0);
	if (ft_strncmp(l[0], "SO", 2) == 0)
		return (map->texture[1] = mlx_load_png(l[1]), free_matrix((void **)l),
			0);
	if (ft_strncmp(l[0], "WE", 2) == 0)
		return (map->texture[2] = mlx_load_png(l[1]), free_matrix((void **)l),
			0);
	if (ft_strncmp(l[0], "EA", 2) == 0)
		return (map->texture[3] = mlx_load_png(l[1]), free_matrix((void **)l),
			0);
	if (ft_strncmp(l[0], "F ", 1) == 0)
		return (map->floor = co_split(ft_split(l[1], ',')),
			free_matrix((void **)l), 0);
	if (ft_strncmp(l[0], "C ", 1) == 0)
		return (map->ceil = co_split(ft_split(l[1], ',')),
			free_matrix((void **)l), 0);
	return (free_matrix((void **)l), 1);
}

int	parse_line(t_map *map, char *line)
{
	if (full(map) == 0)
	{
		if (empty_line(line))
			return (free(line), 0);
		return (set_type(map, ft_split(line, ' '), line));
	}
	else
		return (line_maper(map, line));
}
