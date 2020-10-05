/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 12:38:07 by hovalygtara       #+#    #+#             */
/*   Updated: 2020/10/05 21:58:48 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


void    parse_sphere(t_scene *scene)
{
	t_object	*obj;
	char		**coord;
	char		**rgb;

	if (count_2array(scene->param) != 4 || is_correct(scene) == 0)
		errors_handler(INVALID_SPHERE, scene);
	if (!(obj = (t_object*)malloc(sizeof(t_object))))
		errors_handler(MALLOC_ERR, scene);
	if (!(coord = ft_split(scene->param[1], ',')))
		errors_handler(MALLOC_ERR, scene);
	if (!(rgb = ft_split(scene->param[3], ',')))
		errors_handler(MALLOC_ERR, scene);
	obj->id = SPHERE;
	obj->sphere.diam = ft_atof(scene->param[2]);
	obj->sphere.coord.x = ft_atof(coord[0]);
	obj->sphere.coord.y = ft_atof(coord[1]);
	obj->sphere.coord.z = ft_atof(coord[2]);
	obj->sphere.rgb.r = ft_atoi(rgb[0]);
	obj->sphere.rgb.g = ft_atoi(rgb[1]);
	obj->sphere.rgb.b = ft_atoi(rgb[2]);
	free_2array(coord);
	free_2array(rgb);
	if (rgb_range(obj->sphere.rgb) == 0)
		errors_handler(INVALID_SPHERE, scene);
	ft_lstadd_back(&(scene->objs_list), ft_lstnew(obj));
}

void    parse_plane(t_scene *scene)
{
	t_object	*obj;

	if (count_2array(scene->param) != 4 || is_correct(scene) == 0)
		errors_handler(INVALID_PLANE, scene);
	if (!(obj = (t_object*)malloc(sizeof(t_object))))
		errors_handler(MALLOC_ERR, scene);
	obj->id = PLANE;
	obj->plane.rgb = parse_rgb(scene->param[3], scene);
	obj->plane.orient = parse_xyz(scene->param[2], scene);
	obj->plane.coord = parse_xyz(scene->param[1], scene);
	if (orient_range(obj->plane.orient == 0)
		errors_handler(INVALID_PLANE, scene);
	if (rgb_range(obj->plane.rgb) == 0)
		errors_handler(INVALID_PLANE, scene);
	ft_lstadd_back(&(scene->objs_list), ft_lstnew(obj));
}

void    parse_square(t_scene *scene)
{

}

void    parse_cylinder(t_scene *scene)
{
}

void    parse_triangle(t_scene *scene)
{
}