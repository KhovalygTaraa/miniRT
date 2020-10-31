/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_plane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 01:03:20 by swquinc           #+#    #+#             */
/*   Updated: 2020/11/01 00:18:29 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		plane(t_scene *scene, t_camera *cam, t_xyz ray, t_plane plane)
{
	double	a;
	double	b;
	double	t;

	a = vec_dot(vec_sub(cam->coord, plane.coord), plane.orient);
	b = vec_dot(ray, plane.orient);
	if (b == 0 || (a < 0 && b < 0) || (a > 0 && b > 0))
		return (0);
	t = -a / b;
	if (t < 0)
		return (0);
	scene->mhave.dist2 = t;
	scene->mhave.cur = plane.rgb;
	return (1);
}
