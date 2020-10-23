/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_square.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 01:00:48 by swquinc           #+#    #+#             */
/*   Updated: 2020/10/23 16:36:55 by swquinc          ###   ########.fr       */
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
	t = (c + a) / (c + b);
	vec = vec_sum(vec_mpl(camera->coord, (1 - t)), vec_mpl(ray, t));
	b = vec_dot(vec, square.orient);
	t = a - b;
	if ((int)t == 0)
	{
		t = square.size / 2;
		if (vec.x <= t && vec.x >= -t)
			if (vec.y <= t && vec.y >= -t)
				if (vec.y <= t && vec.y >= -t)
						return (light(vec, square.orient, scene, square.rgb));
	}
	return (0000);
}