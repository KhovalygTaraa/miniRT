/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 12:38:07 by hovalygtara       #+#    #+#             */
/*   Updated: 2020/10/29 05:40:08 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_sphere(t_scene *scene)
{
	t_object	*obj;

	if (count_2array(scene->param) != 4 || is_correct(scene) == 0)
		errors_handler(INVALID_SPHERE, scene);
	if (!(obj = (t_object*)malloc(sizeof(t_object))))
		errors_handler(MALLOC_ERR, scene);
	obj->id = SPHERE;
	obj->sphere.coord = parse_xyz(scene->param[1], scene);
	obj->sphere.diam = ft_atod(scene->param[2]);
	obj->sphere.rgb = parse_rgb(scene->param[3], scene);
	ft_lstadd_back(&(scene->objs_list), ft_lstnew(obj));
}

void	parse_plane(t_scene *scene)
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
	if (orient_range(obj->plane.orient) == 0)
		errors_handler(INVALID_PLANE, scene);
	ft_lstadd_back(&(scene->objs_list), ft_lstnew(obj));
}

void	parse_square(t_scene *scene)
{
	t_object	*obj;

	if (count_2array(scene->param) != 5 || is_correct(scene) == 0)
		errors_handler(INVALID_SQUARE, scene);
	if (!(obj = (t_object*)malloc(sizeof(t_object))))
		errors_handler(MALLOC_ERR, scene);
	obj->id = SQUARE;
	obj->square.coord = parse_xyz(scene->param[1], scene);
	obj->square.orient = parse_xyz(scene->param[2], scene);
	obj->square.size = ft_atod(scene->param[3]);
	obj->square.rgb = parse_rgb(scene->param[4], scene);
	if (orient_range(obj->square.orient) == 0)
		errors_handler(INVALID_SQUARE, scene);
	ft_lstadd_back(&(scene->objs_list), ft_lstnew(obj));
}

void	parse_cylinder(t_scene *scene)
{
	t_object	*obj;

	if (count_2array(scene->param) != 6 || is_correct(scene) == 0)
		errors_handler(INVALID_CYLINDER, scene);
	if (!(obj = (t_object*)malloc(sizeof(t_object))))
		errors_handler(MALLOC_ERR, scene);
	obj->id = CYLINDER;
	obj->cylinder.coord = parse_xyz(scene->param[1], scene);
	obj->cylinder.orient = parse_xyz(scene->param[2], scene);
	obj->cylinder.diam = ft_atod(scene->param[3]);
	obj->cylinder.height = ft_atod(scene->param[4]);
	obj->cylinder.rgb = parse_rgb(scene->param[5], scene);
	if (orient_range(obj->cylinder.orient) == 0)
		errors_handler(INVALID_CYLINDER, scene);
	ft_lstadd_back(&(scene->objs_list), ft_lstnew(obj));
	parse_circle(scene, obj->cylinder, (obj->cylinder.height / -2) + 0.1);
	parse_circle(scene, obj->cylinder, (obj->cylinder.height / 2) - 0.5);
}

void	parse_triangle(t_scene *scene)
{
	t_object	*obj;

	if (count_2array(scene->param) != 5 || is_correct(scene) == 0)
		errors_handler(INVALID_TRIANGLE, scene);
	if (!(obj = (t_object*)malloc(sizeof(t_object))))
		errors_handler(MALLOC_ERR, scene);
	obj->id = TRIANGLE;
	obj->triangle.coord1 = parse_xyz(scene->param[1], scene);
	obj->triangle.coord2 = parse_xyz(scene->param[2], scene);
	obj->triangle.coord3 = parse_xyz(scene->param[3], scene);
	obj->triangle.rgb = parse_rgb(scene->param[4], scene);
	ft_lstadd_back(&(scene->objs_list), ft_lstnew(obj));
}
