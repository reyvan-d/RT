/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburroug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 11:18:48 by aburroug          #+#    #+#             */
/*   Updated: 2016/09/02 11:21:35 by aburroug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float	clamp(float n, float min, float max)
{
	if (n > max)
	{
		if (min > max)
			return (min);
		else
			return (max);
	}
	else
	{
		if (min > n)
			return (min);
		else
			return (n);
	}
}
