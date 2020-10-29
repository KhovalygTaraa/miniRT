/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 01:51:05 by swquinc           #+#    #+#             */
/*   Updated: 2020/10/29 05:08:01 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int		is_shadow(t_scene *s, t_xyz p, t_xyz l, t_light *light)
{
	t_list		*list;
	t_object	*obj;
	t_plane		plane;
	t_camera	cam;
	t_xyz		a;

	cam.coord = p;
	plane.coord = light->coord;
	plane.orient = l;
	a.x = __INT_MAX__;
	a.x = cap(plane, p, l);
	a.y = a.x - 0.1;
	list = s->objs_list;
	while (list)
	{
		obj = list->content;
		if (s->obj.id == obj->id)
		{
			if (s->obj.id == CYLINDER)
				list = list->next->next;
			list = list->next;
			continue ;
		}
		if ((a.x = selector(s, &cam, l, obj)) == 1 && s->mhave.dist2 <= a.y)
			return (1);
		list = list->next;
	}
	return (0);
}

static t_xyz	cylinder_normal(t_cylinder cy, t_xyz p)
{
	t_plane	cy_plane;
	t_xyz	vec;
	double	t;

	cy_plane.coord = cy.coord;
	cy_plane.orient = cy.orient;
	t = cap(cy_plane, p, cy.orient);
	if (t != __INT_MAX__)
	{
		vec = vec_sum(cy.coord, vec_mpl(cy.orient, -t));
		vec = vec_norm(vec_sub(p, vec));
		return (vec);
	}
	t = cap(cy_plane, p, vec_mpl(cy.orient, -1));
	vec = vec_sum(cy.coord, vec_mpl(cy.orient, t));
	vec = vec_norm(vec_sub(p, vec));
	return (vec);
}

static t_rgb	get_color(t_scene *scene, t_xyz p, t_xyz n, t_rgb color)
{
	t_list	*list;
	t_light	*light;
	t_xyz	l;
	t_rgb	color1;
	double	dot;

	list = scene->light_list;
	while (list)
	{
		light = list->content;
		l = vec_norm(vec_sub(light->coord, p));
		dot = vec_dot(n, l);
		if (is_shadow(scene, p, l, light))
			return ((t_rgb){0, 0, 0});
		if (dot <= 0)
		{
			list = list->next;
			continue ;
		}
		color1 = color_bright(light->rgb, light->bright * dot);
		color = final_color(color, new_color(scene->mhave.real, color1));
		list = list->next;
	}
	return (color);
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
		n = cylinder_normal(obj.cylinder, p);
		// n = vec_norm(vec_sub(p, obj.cylinder.coord));
	return (n);
}

int		light_color_shadow(t_scene *scene, t_camera *cam, t_xyz ray)
{
	t_xyz	p;
	t_xyz	n;
	t_rgb	color;

	color = scene->mhave.real;
	color = new_color(color, color_bright(scene->amb.rgb, scene->amb.ratio));
	p = vec_sum(cam->coord, vec_mpl(ray, scene->mhave.dist));
	n = get_normal(scene, p);
	// n = vec_div(n, vec_length(n));
	color = get_color(scene, p, n, color);
	color.r = color.r * 255;
	color.g = color.g * 255;
	color.b = color.b * 255;
	return (0 << 24 | (int)color.r << 16 | (int)color.g << 8 | (int)color.b);
	// scene->mhave.color = light(p, n, scene, scene->mhave.real);
}
