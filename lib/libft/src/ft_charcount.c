/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:56:39 by jeperez-          #+#    #+#             */
/*   Updated: 2025/03/05 14:31:24 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_charcount(const char *str, char c)
{
	int	index;
	int	count;

	count = 0;
	index = 0;
	while (str[index])
	{
		if (str[index] == c)
			count++;
		index++;
	}
	return (count);
}
