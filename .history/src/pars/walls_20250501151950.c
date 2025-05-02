/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:08:15 by auloth            #+#    #+#             */
/*   Updated: 2025/05/01 15:19:50 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int wave_check(char **map, int y, int x, int *open)
{
	while (map[y][x])
	{
		/* code */
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
		}

	}
}
