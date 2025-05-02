/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:32:28 by auloth            #+#    #+#             */
/*   Updated: 2025/05/01 10:35:30 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void print_map(t_map* map)
{
	ft_printf("ceiling color: %d", map->ceil);
	ft_printf("floor color: %d", map->floor);
	ft_printf("texture 1: %s", map->texture[1]);
	ft_printf("texture 1: %s", map->texture[1]);
}
