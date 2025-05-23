/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_extra_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:29:16 by auloth            #+#    #+#             */
/*   Updated: 2025/05/06 14:16:22 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	check_digits(char **colors)
{
	int	x;
	int	y;

	y = 0;
	while (colors[y])
	{
		x = 0;
		while (colors[y][x])
		{
			if (!ft_isdigit(colors[y][x]))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
