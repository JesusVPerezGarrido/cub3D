/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:49:01 by auloth            #+#    #+#             */
/*   Updated: 2025/05/06 14:02:37 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "cub3D.h"
# include <stdio.h>

t_color	co_split(char **color);
void	free_matrix(void **matrix);
int		line_maper(t_map *map, char *line);
int		parse_line(t_map *map, char *line);
void	ft_strreplace(char *str, char old, char new);
void	space_to_wall(char **map);
int		surrounded_walls(char **map);
char	**copy_map(char **map);
int		find_player(t_map *map);
int	check_digits(char **colors);

#endif
