/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:18:37 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/23 14:36:26 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		if (s1[index] == s2[index])
		{
			if (!s1[index])
				return (0);
			index++;
		}
		else
		{
			return (s1[index] - s2[index]);
		}
	}
	return (0);
}
