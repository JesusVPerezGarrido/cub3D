/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:08:15 by auloth            #+#    #+#             */
/*   Updated: 2025/05/01 16:48:36 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int c_check(char c)
{
	if (c == '\n' || c == 0 || c == '	' || c == ' ')
		return(1);
	return(0);
}

void wave_check(char **map, int y, int x, int *open)
{
	if (map[y][x] == '0')
	{
		map
		if (c_check(map[y][x + 1]) == 1)
			*open = 1;
		if (x - 1 < 0 || c_check(map[y][x - 1]) == 1)
			*open = 1;
		if (map[y + 1] == NULL || x > (int)ft_strlen(map[y + 1]) || c_check(map[y + 1][x]) == 1)
			*open = 1;
		if (y - 1 < 0 || x > (int)ft_strlen(map[y - 1]) || c_check(map[y - 1][x]) == 1)
			*open = 1;
		if(*open == 1)
			return;
		wave_check(map, y, x + 1, open);
		wave_check(map, y , x - 1, open);
		wave_check(map, y + 1 , x, open);
		wave_check(map, y - 1, x , open);
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
		x = 0;
		y++;
	}
	return(0);
}
