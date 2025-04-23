/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:38:57 by jeperez-          #+#    #+#             */
/*   Updated: 2025/03/05 14:28:14 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*value;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	value = ft_calloc(len + 1, sizeof(char));
	if (!value)
		return (0);
	ft_strlcpy(value, s, len + 1);
	return (value);
}
