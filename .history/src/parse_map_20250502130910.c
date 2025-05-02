/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:36:58 by jeperez-          #+#    #+#             */
/*   Updated: 2025/05/02 13:09:10 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	error(t_map *map)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (map->texture[i])
			mlx_delete_texture(map->texture[i]);
		i++;
	}
	free_matrix((void **)map->map);
}

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

int unwhanted_chars(char c)
{
	if(c != ' ' && c != '1' && c != '0')
	{
		if(c != 'N' && c != 'N' && c != 'W' && c != 'E' &&)
	}

}

int valid_chars(char **map)
{
	int x;
	int y;

	y = 0;
	while(map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if(unwhanted_chars(map[y][x]) == 1)
				return(1);
			x++;
		}
		y++;
	}
	return(0);
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
		if (parse_line(map, ft_strtrim(line, "\n")) == 1)
			return (free(line), error(map), 1);
		free(line);
		line = get_next_line(fd);
	}
	if (surrounded_walls(copy_map(map->map)) == 1)
		return (error(map), ft_printf("map is not sorrounded\n"), 1);
	if(find_player(map) == 1)
		return (error(map), ft_printf("wrong number of players\n"), 1);
	if(check)
	return (space_to_wall(map->map), 0);
}
