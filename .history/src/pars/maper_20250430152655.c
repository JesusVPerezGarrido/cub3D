/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maper.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:17:59 by auloth            #+#    #+#             */
/*   Updated: 2025/04/30 15:26:55 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void line_maper(t_map* map, char* line)
{
	int i;
	char **n_map;
	i = 0;
	while(map->map[i] != NULL)
		i++;
	n_map = (char **)malloc(i * sizeof(char *));
	if(!n_map)
		return;
	i = 0;
	while(map->map != NULL)
	
}
