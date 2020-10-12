/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_sphere.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 00:54:00 by swquinc           #+#    #+#             */
/*   Updated: 2020/10/12 03:38:12 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		sphere(t_scene *scene, t_camera *cam, t_xyz ray, t_sphere *sp)
{
	double		t;
	t_xyz		p;
	double		x;
	double		t1;
	double		t2;


	t = vec_dot(vec_sub(sp->coord, cam->coord), ray);
	p = vec_sum(cam->coord, vec_mpl(ray, t));
	x = sqrt(sp->diam - pow(vec_length(vec_sub(sp->coord, p)), 2));
	t1 = t - x;
	t2 = t + x;
	if (t1 >= 0 || t2 >= 0)
		return (1);
	else
		return (0);
	
	// tmp = vec_sub(cam->coord, sp->sp.coord); // находим координаты вектора OS, S - координаты центра сферы
	// k1 = vec_dot(ray, ray); 
	// k2 = 2 * vec_dot(tmp, ray); // скалярное произведение OS и точки V
	// k3 = vec_dot(tmp, tmp) - pow(sphere->sphere.diam / 2, 2);  
	// if (q == 0)
	// {
	// 	printf("%f\n", dir.x);
	// 	q = 1;
	// }
	// discr = pow(k2, 2) - (4 * k1 * k3);
	// if (discr < 0)
	// 	return ;
	// if (discr > 0)
	// {
	// 	t1 = (-k2 + sqrt(discr)) / (2 * k1);
	// 	t2 = (-k2 - sqrt(discr)) / (2 * k1);
	// }
	// if (discr == 0)
	// 	t1 = -k2 / 2 * k1;

	// if (t1 >= 0 || t2 >= 0)
	// 	scene->yes = 1;
}