/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put_to_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburroug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 09:26:05 by aburroug          #+#    #+#             */
/*   Updated: 2016/09/03 09:28:25 by aburroug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_pixel_put_to_image(t_img *i, int x, int y, unsigned int color)
{
	if (!i)
		return ;
	if (x > i->width || x < 0 || y < 0 || y > i->height)
		return ;
	i->udata[y * i->sl_div + x * i->bpp_div] = color;
}
