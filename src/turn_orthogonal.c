/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_orthogonal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburroug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 11:22:04 by aburroug          #+#    #+#             */
/*   Updated: 2016/09/02 11:24:32 by aburroug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vect	*turn_orthogonal(t_vect *v1)
{
	float	inverse;
	float	old_x;

	inverse = 1.0 / sqrt(v1->x * v1->x + v1->z * v1->z);
	old_x = v1->x;
	v1->x = -inverse * v1->z;
	v1->z = inverse * old_x;
	return (v1);
}
