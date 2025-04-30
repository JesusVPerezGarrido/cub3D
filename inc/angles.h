/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:32:07 by jeperez-          #+#    #+#             */
/*   Updated: 2025/04/28 11:21:44 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANGLES_H
# define ANGLES_H

# include "vector.h"

# define PI 3.1415926535897932

typedef double	t_deg;
typedef double	t_rad;

t_deg		rtod(t_rad rad);
t_rad		dtor(t_deg deg);
t_vector	rtov(t_rad	r);

#endif
