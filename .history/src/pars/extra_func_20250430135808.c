/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auloth <spotlightcronik@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:47:59 by auloth            #+#    #+#             */
/*   Updated: 2025/04/30 13:58:08 by auloth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int color_spliter(char **color)
{
	int R;
	int G;
	int B;
	int count;

	count = 0;
	while(color[count] != NULL)
		count++;
	if(count != 3)
		return(-1);
	R = atoi(color[0]);
	G = atoi(color[1]);
	B = atoi(color[2]);
	if(R < 0 || R > 255 || G < 0 || G > 255 || B < 0 || B > 255)
		return
}
