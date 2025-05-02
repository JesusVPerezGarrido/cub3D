/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:36:58 by jeperez-          #+#    #+#             */
/*   Updated: 2025/05/01 10:25:39 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	clear_map(t_map *map)
{
	int	index;

	index = 0;
	while (index < 4)
	{
		map->texture[index] = NULL;
		index++;
	}
	map->floor = 0;
	map->ceil = 0;
	map->map = NULL;
	map->player.pos = set_vector(0, 0);
	map->player.dir = set_vector(0, 0);
}

void	parse_file(t_map *map, char *filepath)
{
	int		fd;
	char	*line;

	fd = open(filepath, O_WRONLY);
	if (fd == -1)
	{
		ft_fprintf(STDERR_FILENO, "cub: %s: Error opening map\n", filepath);
		exit(1);
	}
	clear_map(map);
	line = get_next_line(fd);
	while (line)
	{
		ifparse_line(map, line);
		free(line);
		line = get_next_line(fd);
	}
}
