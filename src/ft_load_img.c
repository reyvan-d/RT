/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburroug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 09:28:45 by aburroug          #+#    #+#             */
/*   Updated: 2016/09/03 16:20:49 by aburroug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_img	*ft_load_img(void *mlx, char *src)
{
	t_img	*i;

	if (!src || !(i = (t_img*)malloc(sizeof(t_img))))
		return (NULL);
	if (!(i->img = mlx_xpm_file_to_image(mlx, src, &(i->width), &(i->height))))
		return (NULL);
	i->data = mlx_get_data_addr(i->img, &(i->bpp), &(i->sizeline),
			&(i->endian));
	i->sl_div = i->sizeline / 4;
	i->bpp_div = i->bpp / 8 / 4;
	i->udata = (unsigned int*)i->data;
	return (i);
}
