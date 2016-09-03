/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburroug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 10:32:44 by aburroug          #+#    #+#             */
/*   Updated: 2016/09/03 16:28:25 by aburroug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float	ft_atof(const char *str)
{
	float	res;
	float	factor;
	int		dot;

	res = 0;
	dot = 0;
	while (*str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		factor = *str == '-' ? (str++, -1) : (str++, 1);
	while ((ft_isdigit(*str) || *str == '.') && *str != '\0')
	{
		if (dot == 0 && *str == '.')
			dot = 1;
		else if (ft_isdigit(*str))
		{
			if (dot)
				factor /= 10.0f;
			res = res * 10.0f + (float)(*str - '0');
		}
		str++;
	}
	return (res * factor);
}
