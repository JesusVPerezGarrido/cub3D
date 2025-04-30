/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:52:05 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/28 11:00:26 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "angles.h"

t_deg	rtod(t_rad rad)
{
	t_deg	value;

	value = rad * 180 / PI;
	if (value >= (360))
		value -= 360;
	return (value);
}

t_rad	dtor(t_deg deg)
{
	t_rad	value;

	value = deg * PI / 180;
	if (value >= (2 * PI))
		value -= 2 * PI;
	return (value);
}

t_vector	rtov(t_rad	r)
{
	t_vector	value;

	value.x = cos(r);
	value.y = sin(r);
	return (value);
}
