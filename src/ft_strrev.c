/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburroug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 10:51:05 by aburroug          #+#    #+#             */
/*   Updated: 2016/09/03 16:26:21 by aburroug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

char	*ft_strrev(char *s)
{
	int		i;
	int		len;
	char	tmp;

	
	if (s)
	{
		i = 0;
		len = ft_strlen(s);
		while (i < len / 2)
		{
			tmp = s[i];
			s[i] = s[len - i - 1];
			s[len - i - 1] = tmp;
			i++;
		}
	}
	return (s);
}
