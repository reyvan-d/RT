/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburroug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 11:58:01 by aburroug          #+#    #+#             */
/*   Updated: 2016/09/02 12:13:30 by aburroug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_fill_img(t_img *i, unsigned int color)
{
	int		x;
	int		y;

	x = -1;
	while ((y = -1), ++x < i->width)
		while (++y < i->height)
		{
			i->udata[y * i->sl_div + x * i->bpp_div] = color;
		}
}