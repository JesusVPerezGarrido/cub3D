/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:08:15 by auloth            #+#    #+#             */
/*   Updated: 2025/05/01 14:29:28 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int top(char **map, int *y, int *x)
{

}
int right(char **map, int *y, int *x)
{

}
int bottom(char **map, int *y, int *x)
{

}
int left(char **map, int *y, int *x)
{

}

int surrounded_walls(char **map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (map[y][x] == ' ')
		x++;
	
	if(top(map, &y, &x) != 0)
		return(1);
	if(right(map, &y, &x) != 0)
		return(1);
	if(bottom(map, &y, &x) != 0)
		return(1);
	if(left(map, &y, &x) != 0)
		return(1);

}
