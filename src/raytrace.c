/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 01:49:24 by swquinc           #+#    #+#             */
/*   Updated: 2020/10/23 21:46:15 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_xyz	ray(t_scene *scene, int x, int y, t_camera *camera)
{
	t_xyz	dir;
	double	aspect;

	aspect = (double)scene->res.x / (double)scene->res.y;
	dir.x = (double)x / (double)scene->res.x;
	dir.y = (double)y / (double)scene->res.y;
	dir.x = (dir.x - 0.5) * aspect;
	dir.y = dir.y - 0.5;
	dir.y = -dir.y;
	dir.z = 1.0;
	dir = vec_norm(vec_sub(dir, camera->coord));
	return (dir);
	// dir.x = x - (scene->res.x / 2);
	// dir.y = -y + (scene->res.y / 2);
	// dir.x = dir.x * 1/ scene->res.x;
	// dir.y = dir.y * 1/ scene->res.x;

	// dir.z = 1.0;
	// return (dir);


	// double		fov;
	// t_xyz		res;
	// double		fov2;
	// double		orient;

	// // fov = 2 * tan(camera->fov * M_PI / 360);
	// // fov2 = fov * scene->res.y / scene->res.x;
	// // if (fov == 0)
	// // 	return ((t_xyz){0,0,0});
	// res.x = fov * (x - (scene->res.x / 2)) / scene->res.x;
	// res.y = fov * (-y + (scene->res.y / 2)) / scene->res.x;
	// res.z = 1.0;
	// res = vec_norm(res);
	// return (res);
}

void	raytrace(t_camera *camera, t_scene *scene)
{
	int		x;
	int		y;
	t_xyz	ray_dir;
	t_object	 *object; //потом удалить
	int		i;

	x = 0;
	while (x < scene->res.x)
	{
		y = 0;
		while (y < scene->res.y)
		{
			ray_dir = ray(scene, x, y, camera);
			object = scene->objs_list->content;
			scene->color = square(scene, camera, ray_dir, object->square);
			my_mlx_pixel_put(&camera->image, x, y, scene->color);
			y++;
		}
		x++;
	}
}