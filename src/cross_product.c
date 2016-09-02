/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_product.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburroug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 11:24:42 by aburroug          #+#    #+#             */
/*   Updated: 2016/09/02 11:27:07 by aburroug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vect	*cross_product(t_vect *v1, t_vect *v1)
{
	float	old_x;
	float	old_y;

	old_x = v1->x;
	old_y = v1->y;
	v1->x = v2->y * v1->z - v2->z * old_y;
	v1->y = v2->z * old_x - v2->x * v1->z;
	v1->z = v2->x * old_y - v2->y * old_x;
	return (v1);
}
