/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:02:47 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/28 12:14:48 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

ssize_t	ft_fprintf(int fd, char const *str, ...)
{
	va_list	lst;
	ssize_t	length;

	va_start(lst, str);
	length = ft_print_variadic(str, lst, fd);
	va_end(lst);
	return (length);
}
