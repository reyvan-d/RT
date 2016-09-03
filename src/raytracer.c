/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 15:12:10 by khansman          #+#    #+#             */
/*   Updated: 2016/09/01 16:04:53 by reyvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <pthread.h>

void	create_ray(t_env *env, t_vect *ray, int x, int y)
{
	float	xx;
	float	yy;

	xx = (2 * (x / (float)WIN_WIDTH) - 1) * (float)WIN_RATIO * ZOOM_FACTOR;
	yy = (1 - 2 * (y / (float)WIN_HEIGHT)) * ZOOM_FACTOR;
	ray->x = -cos(env->pitch) * sin(env->yaw)
		+ xx * cos(env->yaw) + yy * sin(env->pitch) * sin(env->yaw);
	ray->y = sin(env->pitch) + yy * cos(env->pitch);
	ray->z = cos(env->pitch) * cos(env->yaw)
		+ xx * sin(env->yaw) - yy * sin(env->pitch) * cos(env->yaw);
	normalize(ray);
}

void	init_spots(t_env *env, t_vect *r_pos, t_vect *r_dir)
{
	int		k;

	k = -1;
	while (++k < env->n_spot)
	{
		set_to(&(env->spots[k].dir), r_dir);
		add(&(env->spots[k].dir), r_pos);
		subtract(&(env->spots[k].dir), &(env->spots[k].pos));
		normalize(&(env->spots[k].dir));
	}
}

int		try_collision(t_env *env, t_vect *r_pos, int id, t_spot *spot)
{
	float	dist;
	int		k;
	t_vect	a;

	k = -1;
	set_to(&a, &(spot->pos));
	subtract(&a, r_pos);
	dist = length_vec(&a);
	normalize(&a);
	while (env->tab_obj[++k])
	{
		if (env->tab_obj[k]->id != id &&
				env->tab_obj[k]->hit(env->tab_obj[k], r_pos, &a, &dist))
			return (1);
	}
	return (0);
}

int		cast_ray(t_env *env, t_vect *ray, int x, int y)
{
	float	dist;
	int		colour;
	t_obj	*res;
	int		k;

	k = -1;
	dist = MAX_DIST;
	res = NULL;
	while (env->tab_obj[++k])
		if (env->tab_obj[k]->hit(env->tab_obj[k], &env->pos, ray, &dist))
			res = env->tab_obj[k];
	if (dist != MAX_DIST)
	{
		env->r_dir = ray;
		env->r_pos = &(env->pos);
		colour_phong(env, res, dist, 1);
		colour = ((int)(env->r * 0xFF) << 16) | ((int)(env->v * 0xFF) << 8)
			| (int)(env->b * 0xFF);
		ft_pixel_put_to_image(env->img, x, y, colour);
		return (1);
	}
	return (0);
}

void	*raytracer(void *e)
{
//	t_vect		ray;
	t_env		*env;
//	t_tvar		var;
		pthread_t	t1;
		pthread_t	t2;
		pthread_t	t3;
		pthread_t	t4;

	env = (t_env *)e;
	set_to(&(env->screen->pos), &(env->dir));
	add(&(env->screen->pos), &(env->pos));
	set_to(&(env->screen->dir), &(env->dir));
	env->t.y = -1;
	env->t.b = (WIN_WIDTH >> 2);
	env->t.c = env->t.b << 1;
	env->t.d = env->t.c + env->t.b;
	while (ADD_IF03)
	{
		/*		//while (++x < env->img->width)
#pragma omp parallel sections
{
#pragma omp section
{
*/	env->t.x = -1;
	if (pthread_create(&t1, NULL, thread1, (void *)env))
		write(1, "Error creating thread\n", 22);
	env->t.x1 = env->t.b;
	if (pthread_create(&t2, NULL, thread2, (void *)env))
		write(1, "Error creating thread\n", 22);
	env->t.x2 = env->t.b << 1;
	if (pthread_create(&t3, NULL, thread3, (void *)env))
		write(1, "Error creating thread\n", 22);
	env->t.x3 = env->t.c + env->t.b;
	if (pthread_create(&t4, NULL, thread4, (void *)env))
		write(1, "Error creating thread\n", 22);
	if (pthread_join(t1, NULL))
		write(1, "Error joining thread\n", 21);
	if (pthread_join(t2, NULL))
		write(1, "Error joining thread\n", 21);
	if (pthread_join(t3, NULL))
		write(1, "Error joining thread\n", 21);
	if (pthread_join(t4, NULL))
		write(1, "Error joining thread\n", 21);
		//if (pthread_create(&thread1, NULL, thread1, (void *)env))
//		tempvar.x1 = var.x1;
//		thread2(env);
//		thread3(env);
//		thread4(env);
		//		if (pthread_create(&thread1, NULL, (void *)&thread1, (void *)env))
		//			write(1, "Error creating thread\n", 22);
		//		if (pthread_join(thread1, NULL))
		//			write(1, "Error joining thread\n", 21);
		//		if (pthread_create(&thread2, NULL, (void *)&thread2, (void *)env))
		//			write(1, "Error creating thread\n", 22);
		//		if (pthread_join(thread2, NULL))
		//			write(1, "Error joining thread\n", 21);
		//		if (pthread_create(&thread3, NULL, (void *)&thread3, (void *)env))
		//			write(1, "Error creating thread\n", 22);
		//		if (pthread_join(thread3, NULL))
		//			write(1, "Error joining thread\n", 21);
		//		if (pthread_create(&thread4, NULL, (void *)&thread4, (void *)env))
		//			write(1, "Error creating thread\n", 22);
		//		if (pthread_join(thread4, NULL))
		//			write(1, "Error joining thread\n", 21);
		/*	while (++x < b)
			{
			create_ray(env, &ray, x, y);
			cast_ray(env, &ray, x, y);
			}
			}
#pragma omp section
{
x1 = b;
while (++x1 < c)
{
create_ray(env, &ray, x1, y);
cast_ray(env, &ray, x1, y);
}
}
#pragma omp section
{
x2 = c;
while (++x2 < d)
{
create_ray(env, &ray, x2, y);
cast_ray(env, &ray, x2, y);
}
}
#pragma omp section
{
x3 = d;
while (++x3 < WIN_WIDTH)
{
create_ray(env, &ray, x3, y);
cast_ray(env, &ray, x3, y);
}
}
}
*/	}
		return (0);
		}
