/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pixel_from_image.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburroug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 12:13:54 by aburroug          #+#    #+#             */
/*   Updated: 2016/09/02 12:21:06 by aburroug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_uint	ft_get_pixel_from_image(t_img *i, int x, int y)
{
	unsigned int color;

	if (!i)
		return (0);
	if (x > i->width || x < 0 || y < 0 || y > i->height)
		return (0);
	color = i->udata[y->y * i->sl_div + x * i->bpp_div];
	return (color);
}
