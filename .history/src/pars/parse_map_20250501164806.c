/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:36:58 by jeperez-          #+#    #+#             */
/*   Updated: 2025/05/01 16:48:06 by auloth           ###   ########.fr       */
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

int	parse_file(t_map *map, char *filepath)
{
	int		fd;
	char	*line;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		ft_fprintf(STDERR_FILENO, "cub: %s: Error opening map\n", filepath);
		exit(1);
	}
	clear_map(map);
	line = get_next_line(fd);
	while (line)
	{
		if(parse_line(map, ft_strtrim(line, "\n")) == 1)
			return(free(line), 1);
		free(line);
		line = get_next_line(fd);
	}
	if (surrounded_walls(cop map->map) == 1)
		return(ft_printf("map is not sorrounded\n"), 1);
	//space_to_wall(map->map);
	return(0);
}
