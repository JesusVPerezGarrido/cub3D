/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:32:28 by auloth            #+#    #+#             */
/*   Updated: 2025/05/01 11:22:45 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void print_map(t_map* map)
{
	int i;

	i = 0;
	ft_printf("ceiling color: %d\n", map->ceil);
	ft_printf("floor color: %d\n", map->floor);
	ft_printf("texture 1: %s\n", map->texture[0]);
	ft_printf("texture 2: %s\n", map->texture[1]);
	ft_printf("texture 3: %s\n", map->texture[2]);
	ft_printf("texture 4: %s", map->texture[3]);

	while(map->map[i] != NULL)
	{
		ft_printf("%s", map->map[i++]);
	}
}
int main(void)
{
	t_map map;
	if(parse_file(&map, "test_file.txt") == 1)
		return(ft_printf("pars failed:!!!"), 1);
	print_map(&map);
}
