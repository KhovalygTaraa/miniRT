/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 01:51:05 by swquinc           #+#    #+#             */
/*   Updated: 2020/10/28 04:01:53 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// static t_xyz	cylinder_normal(t_cylinder cy, t_xyz p)
// {

// }

int		light(t_xyz p, t_xyz n, t_scene *scene, t_rgb rgb)
{
	t_light		*light;
	t_xyz		l;
	double		dot;
	double		i;
	t_rgb		color;

	i = 0;
	light = scene->light_list->content;
	l = vec_sub(light->coord, p);
	dot = vec_dot(n, l);
	i = i + scene->amb.ratio;
	if (dot > 0)
		i = i + (light->bright * dot / (vec_length(n) * vec_length(l)));
	color.r = rgb.r * i;
	color.g = rgb.g * i;
	color.b = rgb.b * i;
	return (0 << 24 | (int)color.r << 16 | (int)color.g << 8 | (int)color.b);
}

static int		get_color(t_scene *scene, t_xyz p, t_xyz n, t_rgb color)
{
	t_list	*list;
	t_light	*light;
	t_xyz	l;
	t_rgb	color1;
	double	dot;
	double	i;

	list = scene->light_list;
	while (list)
	{
		light = list->content;
		l = vec_norm(vec_sub(light->coord, p));
		dot = vec_dot(n, l);
		i = i + scene->amb.ratio;
		if (dot > 0)
		{
			i = i + (light->bright * dot / (vec_length(n) * vec_length(l)));
			// color1 = color_bright(light->rgb, light->bright * dot);
			// color = final_color(color, new_color(scene->mhave.real, color1));
		}
		color = color_bright(color, i);
		list = list->next;
	}
	return (0 << 24 | (int)color.r << 16 | (int)color.g << 8 | (int)color.b);
}

static t_xyz	get_normal(t_scene *scene, t_xyz p)
{
	t_object	obj;
	t_xyz		n;
	t_xyz		vec;
	t_xyz		vec2;

	obj = scene->obj;
	if (obj.id == PLANE)
		n = vec_norm(obj.plane.orient);
	else if (obj.id == TRIANGLE)
	{
		vec = vec_sub(obj.triangle.coord2, obj.triangle.coord1);
		vec2 = vec_sub(obj.triangle.coord3, obj.triangle.coord1);
		n = vec_norm(vec_cross(vec, vec2));
	}
	else if (obj.id == CIRCLE)
		n = vec_norm(obj.circle.orient);
	else if (obj.id == SQUARE)
		n = vec_norm(obj.square.orient);
	else if (obj.id == SPHERE)
		n = vec_norm(vec_sub(p, obj.sphere.coord));
	else if (obj.id == CYLINDER)
		n = vec_norm(obj.cylinder.orient);
	return (n);
}

void	light_color_shadow(t_scene *scene, t_camera *cam, t_xyz ray)
{
	t_xyz	p;
	t_xyz	n;
	t_rgb	color;

	color = scene->mhave.real;
	// color = new_color(color, color_bright(scene->amb.rgb, scene->amb.ratio));
	p = vec_sum(cam->coord, vec_mpl(ray, scene->mhave.dist));
	n = get_normal(scene, p);
	scene->mhave.color = get_color(scene, p, n, color);
	// scene->mhave.color = light(p, n, scene, scene->mhave.real);
}
