/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:39:33 by jeperez-          #+#    #+#             */
/*   Updated: 2025/05/02 11:01:30 by auloth           ###   ########.fr       */
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
	while (sq[index] && ft_strchr(set, s1[index]))
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
