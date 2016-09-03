/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburroug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 09:36:49 by aburroug          #+#    #+#             */
/*   Updated: 2016/09/03 16:22:54 by aburroug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_img	*ft_new_img(void *mlx, int width, int height)
{
	t_img	*i;

	if (!(i = (t_img*)malloc(sizeof(t_img))))
		return (NULL);
	i->width = width;
	i->height = height;
	i->img = mlx_new_image(mlx, width, height);
	i->data = mlx_get_data_addr(i->img, &(i->bpp), &(i->sizeline),
			&(i->endian));
	i->sl_div = i->sizeline / 4;
	i->bpp_div = i->bpp / 8 / 4;
	i->udata = (unsigned int*)i->data;
	return (i);
}
