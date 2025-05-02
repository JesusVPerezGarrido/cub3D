/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:08:15 by auloth            #+#    #+#             */
/*   Updated: 2025/05/01 15:29:14 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"


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
    for (i = 0; map[i] != NULL; i++)
    {
        map_copy[i] = strdup(map[i]);
        if (!map_copy[i])
        {
            while (--i >= 0)
                free(map_copy[i]);
            free(map_copy);
            return (NULL);
        }
    }
    map_copy[i] = NULL;

    return (map_copy);
}

void wave_check(char **map, int y, int x, int *open)
{
	while (map[y][x] == '0')
	{
		if (map[y][x])
	}

}

int surrounded_walls(char **map)
{
	int x;
	int y;
	int open;

	x = 0;
	y = 0;
	open = 0;
	while (map[y] != NULL)
	{
		while (map[y][x] != 0)
		{
			if(map[y][x] == '0')
			{
				wave_check(map, y, x, &open);
				if(open == 1)
					return(1);
			}
			x++;
		}
		y++;
	}
}
