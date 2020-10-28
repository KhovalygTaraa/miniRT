/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_triangle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 01:04:28 by swquinc           #+#    #+#             */
/*   Updated: 2020/10/28 02:10:23 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double vec_t(t_xyz vec)
{
	double	a;
	a = vec.x + vec.y + vec.z;
	return (a);
}

int		triangle(t_scene *scene, t_camera *cam, t_xyz ray, t_triangle tr)
{
	double	x;
	double	z;
	double	t;
	t_xyz	vec;
	t_xyz	vec2;
	t_xyz	tvec;
	t_xyz	pvec;

	vec = vec_sub(tr.coord2, tr.coord1);
	vec2 = vec_sub(tr.coord3, tr.coord1);
	pvec = vec_cross(ray, vec2);
	t = vec_dot(vec, pvec);
	if (fabs(t) < 0.00001)
		return (0);
	t = 1 / t;
	tvec = vec_sub(cam->coord, tr.coord1);
	x = vec_dot(tvec, pvec) * t;
	if ( x < 0 || x > 1)
		return (0);
	tvec = vec_cross(tvec, vec);
	z = vec_dot(ray, tvec) * t;
	if (z < 0 || x + z > 1)
		return (0);
	scene->mhave.dist2 = vec_dot(vec2, tvec) * t;
	scene->mhave.cur = tr.rgb;
	return (1);
	// t = vec_dot(vec, vec_cross(ray, vec2));
	// if (fabs(t) < 0.00001)
	// 	return (0);
	// t = 1 / t;
	// x = t * vec_dot(vec_sub(cam->coord, tr.coord1), vec_cross(ray, vec2));
	// if (x < 0 || x > 1)
	// 	return (0);
	// z = t * vec_dot(ray, vec_cross(vec_sub(cam->coord, tr.coord1), vec));
	// if (z < 0 || x + z > 1)
	// 	return (0);
	// t = t * vec_dot(vec2, vec_cross(vec_sub(cam->coord, tr.coord1), vec));
	// scene->color.dist2 = t;
	// printf("%d\n", i);
	// i++;
	// return (0255000000);


	// orient = vec_sub(tr.coord1, tr.coord2);
	// orient = vec_norm(vec_cross(orient, vec_sub(tr.coord2, tr.coord3)));
	// x = vec_dot(vec_sub(cam->coord, tr.coord1), orient);
	// z = vec_smth(cam->coord, orient);
	// t = (z - x) / (z + vec_dot(ray, orient));
	// vec = vec_sum(cam->coord, vec_mpl(vec_sub(ray, cam->coord), t));
	// tr.coord2 = vec_sub(tr.coord2, tr.coord1);
	// tr.coord3 = vec_sub(tr.coord3, tr.coord1);
	// tr.coord1 = vec_sub(vec, tr.coord1);
	// x = vec_t(vec_cross(tr.coord1, tr.coord2)) / vec_t(vec_cross(tr.coord3, tr.coord2));
	// if (x > 0 && x < 1)
	// {
	// 	// z = (tr.coord1.x - x * tr.coord3.x) / tr.coord2.x;
	// 	z = vec_t(vec_sub(tr.coord1, vec_mpl(tr.coord3, x))) / vec_t(tr.coord2);
	// 	if (z >= 0 && z + x <= 1)
	// 	{
	// 		scene->color.dist2 = t;
	// 		// return (light(vec, orient, scene, tr.rgb));
	// 		return (0255000000);
	// 	}
	// }
}