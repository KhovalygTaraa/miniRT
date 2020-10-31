/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_circle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 23:02:16 by swquinc           #+#    #+#             */
/*   Updated: 2020/10/31 21:38:37 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		circle(t_scene *scene, t_camera *camera, t_xyz ray, t_circle cr)
{
	double		a;
	double		b;
	double		t;
	t_xyz		vec;

	a = vec_dot(vec_sub(camera->coord, cr.coord), cr.orient);
	b = vec_dot(ray, cr.orient);
	if (b == 0 || (a < 0 && b < 0) || (a > 0 && b > 0))
		return (0);
	t = -a / b;
	if (t < 0)
		return (0);
	vec = vec_sub(vec_sum(camera->coord, vec_mpl(ray, t)), cr.coord);	
	a = sqrt(vec_dot(vec, vec));
	if (a <= cr.diam / 2)
	{
		scene->mhave.dist2 = t;
		scene->mhave.cur = cr.rgb;
		return (1);
	}
	return (0);
}