/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:13:10 by jeperez-          #+#    #+#             */
/*   Updated: 2025/03/05 14:31:04 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstinsert(t_list *node, t_list *insert)
{
	if (!node || !insert)
		insert->next = node->next;
	insert->prev = node;
	if (node->next)
		node->next->prev = insert;
	node->next = insert;
	return (insert);
}
