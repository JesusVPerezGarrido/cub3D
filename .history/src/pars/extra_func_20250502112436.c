/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:47:59 by auloth            #+#    #+#             */
/*   Updated: 2025/05/02 11:24:36 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_color	co_split(char **color)
{
	int	Red;
	int	Green;
	int	Blue;
	int	count;

	count = 0;
	while (color[count] != NULL)
		count++;
	if (count != 3)
		return (0);
	Red = atoi(color[0]);
	Green = atoi(color[1]);
	Blue = atoi(color[2]);
	if (Red < 0 || Red > 255 || Green < 0 || Green > 255 || Blue < 0 || Blue > 255)
		return (0);
	return (free_matrix((void **)color), set_color(Red, Green, Blue, 255));
}

void	ft_strreplace(char *str, char old, char new_c)
{
	size_t	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		if (str[i] == old)
			str[i] = new_c;
		i++;
	}
}

void	free_matrix(void **matrix)
{
	int	i;

	i = 0;
	while (matrix && matrix[i] != NULL)
		free(matrix[i]), i++;
	free(matrix[i]);
	free(matrix);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->texture[0] != NULL)
		free(map->texture[0]);
	if (map->texture[0] != NULL)
		free(map->texture[0]);
	if (map->texture[0] != NULL)
		free(map->texture[0]);
	if (map->texture[0] != NULL)
		free(map->texture[0]);
	while (map->map[i] != NULL)
		free(map->map[i++]);
	free(map);
}

char	**copy_map(char **map)
{
	int		i;
	char	**map_copy;

	i = 0;
	while (map[i] != NULL)
		i++;
	map_copy = (char **)malloc((i + 1) * sizeof(char *));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (map[i] != NULL)
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
		{
			while (--i >= 0)
				free(map_copy[i]);
			free(map_copy);
			return (NULL);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}
