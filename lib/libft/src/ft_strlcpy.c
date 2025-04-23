/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:47:12 by jeperez-          #+#    #+#             */
/*   Updated: 2025/03/05 14:19:07 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t destsize)
{
	size_t	index;

	if (!dst || !src)
		return (ft_strlen(src));
	index = 0;
	if (destsize == 0)
		return (ft_strlen(src));
	while (src[index] && destsize > index + 1)
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = 0;
	return (ft_strlen(src));
}
