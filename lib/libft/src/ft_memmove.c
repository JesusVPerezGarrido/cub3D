/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:41:58 by jeperez-          #+#    #+#             */
/*   Updated: 2025/03/05 13:57:01 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			index;

	if (!dest || !src || dest == src)
		return (dest);
	if (dest > src)
		ft_memcpy(dest, src, n);
	else
	{
		index = 0;
		while (index < n)
		{
			((t_byte *)dest)[index] = ((t_byte *)src)[index];
			index++;
		}
	}
	return (dest);
}
