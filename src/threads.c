/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 12:04:11 by reyvan-d          #+#    #+#             */
/*   Updated: 2016/09/01 16:26:31 by reyvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	*thread1(void *e)
{
	t_vect	ray;
	t_env	env;
	t_tvar	var;

	ft_bzero(&ray, sizeof(t_vect));
	ft_memcpy(&env, e, sizeof(t_env));
	ft_memcpy(&var, &env.t, sizeof(t_tvar));
	while (++var.x <= var.b)
	{
		create_ray(&env, &ray, var.x, var.y);
		cast_ray(&env, &ray, var.x, var.y);
	}
	return (0);
}

void	*thread2(void *e)
{
	t_vect 	ray;
	t_env  	env;
	t_tvar 	var;

	ft_bzero(&ray, sizeof(t_vect));
	ft_memcpy(&env, e, sizeof(t_env));
	ft_memcpy(&var, &env.t, sizeof(t_tvar));
	while (++var.x1 <= var.c)
	{
		create_ray(&env, &ray, var.x1, var.y);
		cast_ray(&env, &ray, var.x1, var.y);
	}
	return (0);
}

void	*thread3(void *e)
{
	t_vect 	ray;
	t_env  	env;
	t_tvar 	var;

	ft_bzero(&ray, sizeof(t_vect));
	ft_memcpy(&env, e, sizeof(t_env));
	ft_memcpy(&var, &env.t, sizeof(t_tvar));
	while (++var.x2 <= var.d)
	{
		create_ray(&env, &ray, var.x2, var.y);
		cast_ray(&env, &ray, var.x2, var.y);
	}
	return (0);
}

void	*thread4(void *e)
{
	t_vect 	ray;
	t_env  	env;
	t_tvar 	var;

	ft_bzero(&ray, sizeof(t_vect));
	ft_memcpy(&env, e, sizeof(t_env));
	ft_memcpy(&var, &env.t, sizeof(t_tvar));
	while (++var.x3 <= WIN_WIDTH)
	{
		create_ray(&env, &ray, var.x3, var.y);
		cast_ray(&env, &ray, var.x3, var.y);
	}
	return (0);
}
