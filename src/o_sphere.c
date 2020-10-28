/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_sphere.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 00:54:00 by swquinc           #+#    #+#             */
/*   Updated: 2020/10/28 02:09:49 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		sphere(t_scene *scene, t_camera *cam, t_xyz ray, t_sphere sp)
{
	t_xyz		k;
	t_xyz		n;
	double		t1;
	double		t2;

	k.x = vec_dot(ray, ray);
	k.y = 2 * vec_dot(ray, vec_sub(cam->coord, sp.coord));
	k.z = vec_dot(vec_sub(cam->coord, sp.coord), vec_sub(cam->coord, sp.coord)) - pow(sp.diam / 2, 2);
	if ((k.y * k.y - 4 * k.x * k.z) < 0)
		return (0);
	t1 = (-k.y + sqrt(k.y * k.y - (4 * k.x * k.z))) / (2 * k.x);
	t2 = (-k.y - sqrt(k.y * k.y - (4 * k.x * k.z))) / (2 * k.x);
	if (t1 <= t2)
		scene->mhave.dist2 = t1;
	else
		scene->mhave.dist2 = t2;
	// k = vec_sum(cam->coord, vec_mpl(vec_sub(ray, cam->coord), scene->color.dist2));
	// n = vec_sub(k, sp.coord);
	// n = vec_div(n, vec_length(n));
	scene->mhave.cur = sp.rgb;
	return (1);
}