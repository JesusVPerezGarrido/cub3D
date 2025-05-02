/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:47:59 by auloth            #+#    #+#             */
/*   Updated: 2025/05/01 16:46:05 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_color co_split(char **color)
{
	int R;
	int G;
	int B;
	int count;

	count = 0;
	while(color[count] != NULL)
		count++;
	if(count != 3)
		return(0);
	R = atoi(color[0]);
	G = atoi(color[1]);
	B = atoi(color[2]);
	if(R < 0 || R > 255 || G < 0 || G > 255 || B < 0 || B > 255)
		return(0);
	return(free_matrix((void **)color), set_color(R, G, B, 255));
}

void	ft_strreplace(char *str, char old, char new)
{
	size_t	i;

	if (!str)
		return;
	i = 0;
	while (str[i])
	{
		if (str[i] == old)
			str[i] = new;
		i++;
	}
}

void free_matrix(void **matrix)
{
	int i;

	i = 0;
	while (matrix && matrix[i] != NULL)
		free(matrix[i]), i++;
	free(matrix[i]);
	free(matrix);
}

void free_map(t_map* map)
{
	int i;

	i = 0;
	if(map->texture[0] != NULL)
		free(map->texture[0]);
	if(map->texture[0] != NULL)
		free(map->texture[0]);
	if(map->texture[0] != NULL)
		free(map->texture[0]);
	if(map->texture[0] != NULL)
		free(map->texture[0]);
	while (map->map[i] != NULL)
		free(map->map[i++]);
	free(map);
}

char **copy_map(char **map)
{
    int i;
    char **map_copy;

    // Count the number of rows in the map
    for (i = 0; map[i] != NULL; i++)
        ;

    // Allocate memory for the new map (including space for the NULL terminator)
    map_copy = (char **)malloc((i + 1) * sizeof(char *));
    if (!map_copy)
        return (NULL);

    // Copy each row of the map
    for (i = 0; map[i] != NULL; i++)
    {
        map_copy[i] = strdup(map[i]); // Duplicate the string
        if (!map_copy[i])
        {
            // Free already allocated rows in case of failure
            while (--i >= 0)
                free(map_copy[i]);
            free(map_copy);
            return (NULL);
        }
    }
    map_copy[i] = NULL;

    return (map_copy);
}
