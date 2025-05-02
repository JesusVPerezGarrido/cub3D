/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:54:16 by auloth            #+#    #+#             */
/*   Updated: 2025/04/30 13:14:11 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

set_type(t_map *map, char* line, int c)
{
	if(ft_strncmp(line, ""))
}

parse_line(t_map *map, char *line)
{
	int i;

	i = 0;
	while(line[i] == ' ')
		i++;
	set_type(map, line, i);
}
