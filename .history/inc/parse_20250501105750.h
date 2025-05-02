/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:49:01 by auloth            #+#    #+#             */
/*   Updated: 2025/05/01 10:57:50 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_color co_split(char **color);
void free_matrix(void **matrix);
int line_maper(t_map* map, char* line);
int parse_line(t_map *map, char *line);
