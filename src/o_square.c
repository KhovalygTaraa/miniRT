/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_square.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 01:00:48 by swquinc           #+#    #+#             */
/*   Updated: 2020/10/23 21:46:39 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		square(t_scene *scene, t_camera *camera, t_xyz ray, t_square square)
{
	double	a;
	double	b;
	double	c;
	double	t;
	t_xyz	vec;

	a = vec_dot(vec_sub(camera->coord, square.coord), square.orient);
	b = vec_dot(ray, square.orient);
	c = vec_smt(camera->coord, square.orient);
	t = (c - a) / (c + b);
	vec = vec_sum(vec_mpl(camera->coord, (1 - t)), vec_mpl(ray, t));
	b = vec_dot(vec, square.orient);
	vec = vec_sub(vec, square.coord);
	a = a + b;
	if ((int)a != 0)
		return (0000);
	c = (square.size / 2);
	if (fabs(vec.x) > c || fabs(vec.y) > c || fabs(vec.z) > c)
		return (0000);
	if (t > 0)
		return (light(vec, square.orient, scene, square.rgb));
	return (0000);
}