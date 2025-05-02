/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:39:33 by jeperez-          #+#    #+#             */
/*   Updated: 2025/03/05 14:23:31 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*value;
	int		index;
	int		length;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	index = 0;
	while (ft_strchr(set, s1[index]))
	{
		index++;
	}
	length = ft_strlen(s1);
	while (ft_strchr(set, s1[length]))
	{
		length--;
	}
	value = ft_substr(s1, index, length - index + 1);
	if (!value)
		return (0);
	return (value);
}
