/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:37:48 by jeperez-          #+#    #+#             */
/*   Updated: 2025/03/05 12:29:51 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*value;
	size_t	mem_size;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if ((nmemb * size) / nmemb != size)
		return (0);
	mem_size = nmemb * size;
	value = malloc(mem_size);
	if (!value)
		return (0);
	ft_bzero(value, mem_size);
	return (value);
}
