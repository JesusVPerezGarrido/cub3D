/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:10:38 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/23 14:35:31 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*value;
	unsigned int	sub_len;

	if (!s)
		return (NULL);
	sub_len = ft_strlen(s);
	if (start > sub_len)
		return (ft_calloc(1, 1));
	sub_len = ft_lowest(sub_len - start, len);
	value = ft_calloc(sub_len + 1, sizeof(char));
	if (!value)
		return (0);
	ft_strlcat(value, s + start, sub_len + 1);
	return (value);
}
