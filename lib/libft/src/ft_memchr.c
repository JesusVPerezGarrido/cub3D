/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:12:18 by jeperez-          #+#    #+#             */
/*   Updated: 2025/03/05 13:54:05 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		index;
	char	mem_c;

	c = c & 0xFF;
	index = 0;
	while (n)
	{
		mem_c = ((t_byte *)s)[index];
		if (mem_c == c)
			return (&(((t_byte *)s)[index]));
		index++;
		n--;
	}
	return (0);
}
