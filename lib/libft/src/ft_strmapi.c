/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:51:41 by jeperez-          #+#    #+#             */
/*   Updated: 2025/03/05 14:20:07 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		index;
	char	*value;

	index = 0;
	value = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!value)
		return (0);
	while (s[index])
	{
		value[index] = (*f)(index, s[index]);
		index++;
	}
	return (value);
}
