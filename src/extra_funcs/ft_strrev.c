/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburroug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 10:51:05 by aburroug          #+#    #+#             */
/*   Updated: 2016/09/03 10:55:42 by aburroug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

char	*ft_strrev(char *s)
{
	int		i;
	int		len;
	char	tmp;

	
	if (str)
	{
		i = 0;
		len = ft_strlen(str);
		while (i < len / 2)
		{
			tmp = str[i];
			str[i] = str[len - i - 1];
			str[len - i - 1] = tmp;
			i++;
		}
	}
	return (str);
}
