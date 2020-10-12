/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 01:49:24 by swquinc           #+#    #+#             */
/*   Updated: 2020/10/12 15:42:35 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_xyz	ray(t_scene *scene, int x, int y, t_camera *camera)
{
	double		fov;
	t_xyz		res;
	double		fov2;

	fov = tan(camera->fov * M_PI / 360);
	fov2 = fov * scene->res.y / scene->res.x;
	if (fov == 0)
		return ((t_xyz){0,0,0});
	res.x = fov * (x - scene->res.x / 2);
	res.y = ((-1 * y) + scene->res.y / 2) * fov2;
	res.z = 1.0;
	return (res);
}

void	raytrace(t_camera *camera, t_scene *scene)
{
	int		x;
	int		y;
	t_xyz	ray1;
	t_sphere	 *sphere1; //потом удалить

	x = 0;
	while (x < scene->res.x)
	{
		y = 0;
		while (y < scene->res.y)
		{
			ray1 = ray(scene, x, y, camera);
			sphere1 = scene->objs_list->content;
			scene->yes = sphere(scene, camera, ray1, sphere1);
			if (scene->yes == 1)
				my_mlx_pixel_put(&camera->image, x, y, 0000255000);
			else
				my_mlx_pixel_put(&camera->image, x, y, 0255000000);
			y++;
		}
		x++;
	}
}