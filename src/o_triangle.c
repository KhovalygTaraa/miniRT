/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_triangle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 01:04:28 by swquinc           #+#    #+#             */
/*   Updated: 2020/10/31 05:46:59 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
}