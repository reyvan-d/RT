/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp_vec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburroug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 11:16:12 by aburroug          #+#    #+#             */
/*   Updated: 2016/09/02 11:18:26 by aburroug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vect	*clamp_vec(t_vect *v1, float min, float max)
{
	v1->x = clamp(v1->x, min, max);
	v1->y = clamp(v1->y, min, max);
	v1->z = clamp(v1->z, min, max);
	return (v1);
}
