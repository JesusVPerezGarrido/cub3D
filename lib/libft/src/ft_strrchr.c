/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:11:49 by jeperez-          #+#    #+#             */
/*   Updated: 2025/03/05 14:21:55 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	index;

	index = ft_strlen(s);
	c %= 0xFF;
	if (c == 0)
		return (((char *)s) + index);
	while (index)
	{
		if (s[index - 1] == c)
			return (((char *)s) + index - 1);
		index--;
	}
	return (0);
}
