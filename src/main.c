/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:25:09 by jeperez-          #+#    #+#             */
/*   Updated: 2025/05/02 13:56:32 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	check_args(int ac, char **av)
{
	char	*extension;

	if (ac != 2)
	{
		ft_fprintf(STDERR_FILENO, "Usage: cub3D MAP\n");
		exit(1);
	}
	extension = ft_strrchr(av[1], '.');
	if (!av[1][0] || !extension || ft_strcmp(extension, ".cub"))
	{
		ft_fprintf(STDERR_FILENO, "cub3D: %s: ", av[1]);
		ft_fprintf(STDERR_FILENO, "Map must have .cub extension\n");
		exit(1);
	}
	if (access(av[1], F_OK) == -1)
	{
		ft_fprintf(STDERR_FILENO, "cub3D: %s: not found\n", av[1]);
		exit(1);
	}
	if (access(av[1], R_OK) == -1)
	{
		exit(1);
		ft_fprintf(STDERR_FILENO, "cub3D: %s: permission denied \n", av[1]);
	}
}

int	main(int ac, char **av)
{
	t_cub3d	cub;

	check_args(ac, av);
	if (parse_file(&cub.map, av[1]) == 0)
		cub_start(&cub);
}
