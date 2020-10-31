/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 01:49:24 by swquinc           #+#    #+#             */
/*   Updated: 2020/11/01 00:05:01 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_xyz	to_world(t_xyz pixel, t_camera *cam)
{
	double		coff;
	t_xyz		a;
	t_xyz		b;
	t_xyz		c;
	t_xyz		res;

	coff = sqrt(pow(cam->orient.x, 2) + pow(cam->orient.z, 2));
	a.x = pixel.x * (cam->orient.z / coff);
	a.y = pixel.y * (-1 * (cam->orient.x * cam->orient.y) / coff);
	a.z = pixel.z * (cam->orient.x);
	b.x = 0;
	b.y = pixel.y * coff;
	b.z = pixel.z * cam->orient.y;
	c.x = pixel.x * (cam->orient.x / coff);
	c.y = pixel.y * (-1 * (cam->orient.y * cam->orient.z) / coff);
	c.z = pixel.z * cam->orient.z;
	res.x = a.x + a.y + a.z;
	res.y = b.x + b.y + b.z;
	res.z = c.x + c.y + c.z;
	return (res);
}

static t_xyz	ray(t_scene *scene, int x, int y, t_camera *camera)
{
	t_xyz		dir;
	double		aspect;
	double		fov;

	fov = tan(camera->fov / 2 * M_PI / 180);
	aspect = (double)scene->res.x / (double)scene->res.y;
	dir.x = 2 * ((double)x + 0.5) / (double)scene->res.x;
	dir.y = 2 * ((double)y + 0.5) / (double)scene->res.y;
	dir.x = (dir.x - 1) * aspect * fov;
	dir.y = (1 - dir.y) * fov;
	dir.z = 1.0;
	dir = to_world(dir, camera);
	dir = vec_norm(dir);
	return (dir);
}

int				selector(t_scene *s, t_camera *cam, t_xyz ray, t_object *object)
{
	int			t;

	t = 0;
	if (object->id == SPHERE)
		t = sphere(s, cam, ray, object->sphere);
	else if (object->id == PLANE)
		t = plane(s, cam, ray, object->plane);
	else if (object->id == SQUARE)
		t = square(s, cam, ray, object->square);
	else if (object->id == TRIANGLE)
		t = triangle(s, cam, ray, object->triangle);
	else if (object->id == CYLINDER)
		t = cylinder(s, cam, ray, object->cylinder);
	else if (object->id == CIRCLE)
		t = circle(s, cam, ray, object->circle);
	return (t);
}

static void		render_color(t_camera *cam, t_scene *s, t_xyz ray)
{
	t_object	*object;
	t_list		*list;

	list = s->objs_list;
	s->mhave.color = 0000;
	s->mhave.dist = __INT_MAX__;
	while (list != 0)
	{
		object = list->content;
		s->mhave.is_i = selector(s, cam, ray, object);
		if (s->mhave.is_i == 1)
			if (s->mhave.dist2 <= s->mhave.dist)
			{
				s->mhave.dist = s->mhave.dist2;
				s->obj = cpy_obj(object);
				s->mhave.real = s->mhave.cur;
			}
		list = list->next;
	}
	if (s->mhave.dist == __INT_MAX__)
		return ;
	s->mhave.color = light_color_shadow(s, cam, ray);
}

void			raytrace(t_camera *camera, t_scene *scene)
{
	int			x;
	int			y;
	t_xyz		ray_dir;

	x = 0;
	while (x < scene->res.x)
	{
		y = 0;
		while (y < scene->res.y)
		{
			ray_dir = ray(scene, x, y, camera);
			render_color(camera, scene, ray_dir);
			my_mlx_pixel_put(&camera->image, x, y, scene->mhave.color);
			y++;
		}
		x++;
	}
}
