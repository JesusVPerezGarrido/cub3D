/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:08:16 by jeperez-          #+#    #+#             */
/*   Updated: 2025/03/05 14:31:15 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_index;
	size_t	s_index;

	if (!dst || !src)
		return (ft_strlen(src) + ft_strlen(dst));
	d_index = 0;
	while (dst[d_index] && size > d_index + 1)
		d_index++;
	if (dst[d_index])
		return (size + ft_strlen(src));
	s_index = 0;
	while (src[s_index] && size > (d_index + s_index + 1))
	{
		dst[d_index + s_index] = src[s_index];
		s_index++;
	}
	dst[d_index + s_index] = 0;
	return (d_index + ft_strlen(src));
}
