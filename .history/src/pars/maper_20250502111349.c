/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maper.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:17:59 by auloth            #+#    #+#             */
/*   Updated: 2025/05/02 11:13:49 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	space_to_wall(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		ft_strreplace(map[i++], ' ', '1');
}

int	line_maper(t_map *map, char *line)
{
	int		i;
	char	**n_map;

	i = 0;
	while (map->map && map->map[i])
		i++;
	n_map = (char **)malloc((i + 2) * sizeof(char *));
	if (!n_map)
		return (free(1);
	i = 0;
	while (map->map && map->map[i] != NULL)
		n_map[i] = ft_strdup(map->map[i]), i++;
	n_map[i] = ft_strdup(line);
	n_map[i + 1] = NULL;
	if (map->map)
		free_matrix((void **)map->map);
	map->map = n_map;
	free(line);
	return (0);
}

int valid_player_pos(t_map *map, char c, int x, int y)
{
	if(c == 'N')
	{
		map->player.pos = set_vector(x, y);
		map->player.dir = set_vector(0, -1);
		return(0);
	}
	if(c == 'S')
	{
		map->player.pos = set_vector(x, y);
		map->player.dir = set_vector(0, 1);
		return(0);
	}
	if(c == 'W')
	{
		map->player.pos = set_vector(x, y);
		map->player.dir = set_vector(-1, 0);
		return(0);
	}
	if(c == 'E')
	{
		map->player.pos = set_vector(x, y);
		map->player.dir = set_vector(1, 0);
		return(0);
	}
	return(1);
}

int	find_player(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (valid_player_pos(map, map->map[y][x], x, y) == 0)
				return(0);
			x++;
		}
		y++;
	}
	return(1);
}
