/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_square.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 01:00:48 by swquinc           #+#    #+#             */
/*   Updated: 2020/10/26 13: by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		square(t_scene *scene, t_camera *cam, t_xyz ray, t_square square)
{
	double	a;
	double	b;
	double	c;
	double	t;
	t_xyz	vec;

	a = vec_dot(vec_sub(cam->coord, square.coord), square.orient);
	b = vec_dot(ray, square.orient);
	if (b == 0 || (a < 0 && b < 0) || (a > 0 && b > 0))
		return (0);
	t = -a / b;
	if (t < 0)
		return (0);
	vec = vec_sub(vec_sum(vec_mpl(ray, t), cam->coord), square.coord);
	c = (square.size / 2);
	if (fabs(vec.x) > c || fabs(vec.y) > c || fabs(vec.z) > c)
		return (0);
	if (t < 0)
		return (0);
	scene->mhave.dist2 = t;
	scene->mhave.cur = square.rgb;
	return (1);
}