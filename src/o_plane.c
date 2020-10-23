/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_plane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 01:03:20 by swquinc           #+#    #+#             */
/*   Updated: 2020/10/23 21:47:19 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		plane(t_scene *scene, t_camera *camera, t_xyz ray, t_plane plane)
{
	double	a;
	double	b;
	double	c;
	double	t;
	t_xyz	vec;

	a = vec_dot(vec_sub(camera->coord, plane.coord), plane.orient);
	b = vec_dot(ray, plane.orient);
	c = vec_smt(camera->coord, plane.orient);
	t = (c - a) / (c + b);
	vec = vec_sum(vec_mpl(camera->coord, (1 - t)), vec_mpl(ray, t));
	vec = vec_norm(vec);
	b = vec_dot(vec, plane.orient);
	t = a + b;
	if ((int)t == 0)
		return (light(vec, plane.orient, scene, plane.rgb));
	return (0000);
}