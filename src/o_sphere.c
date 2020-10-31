/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_sphere.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 00:54:00 by swquinc           #+#    #+#             */
/*   Updated: 2020/11/01 00:36:38 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		sphere(t_scene *scene, t_camera *cam, t_xyz ray, t_sphere sp)
{
	t_xyz		k;
	t_xyz		n;
	double		t1;
	double		t2;

	n = vec_sub(cam->coord, sp.coord);
	k.x = vec_dot(ray, ray);
	k.y = 2 * vec_dot(ray, n);
	k.z = vec_dot(n, n) - pow(sp.diam / 2, 2);
	if ((t2 = (k.y * k.y) - (4 * k.x * k.z)) < 0)
		return (0);
	t1 = (-k.y + sqrt(t2)) / (2 * k.x);
	t2 = (-k.y - sqrt(t2)) / (2 * k.x);
	if (t1 < 0 && t2 >= 0)
		scene->mhave.dist2 = t2;
	else if (t2 < 0 && t1 >= 0)
		scene->mhave.dist2 = t1;
	else if (t1 >= 0 && t2 >= 0)
		scene->mhave.dist2 = fmin(t1, t2);
	else if (t1 < 0 && t2 < 0)
		return (-1);
	scene->mhave.cur = sp.rgb;
	return (1);
}
