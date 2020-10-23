/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_plane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 01:03:20 by swquinc           #+#    #+#             */
/*   Updated: 2020/10/20 22:43:59 by swquinc          ###   ########.fr       */
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
	t = (c + a) / (c + b);
	vec = vec_sum(vec_mpl(camera->coord, (1 - t)), vec_mpl(ray, t));
	vec = vec_norm(vec);
	a = vec_dot(vec_sub(camera->coord, plane.coord), plane.orient);
	b = vec_dot(vec, plane.orient);
	t = a - b;
	if ((int)t == 0)
		return (1);
	return (0);
	// a = vec_dot(vec_sub(camera->coord, plane.coord), plane.orient);
	// b = vec_dot(ray, plane.orient);
	// if (b == 0 || a < 0 && b < 0 || a > 0 && b > 0)
	// 	return (0);
	// t = -a / b;
	// if (t > 0)
	// 	return (1);
	// else
	// return (0);
}