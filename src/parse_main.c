/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 17:55:08 by hovalygtara       #+#    #+#             */
/*   Updated: 2020/10/22 13:03:57 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parsing(char *rt_file, t_scene *scene)
{
	int		fd;
	char	*line;
	int		i;

	if ((fd = open(rt_file, O_RDONLY)) < 0)
		errors_handler(CANNOT_OPEN_FILE, scene);
	while (get_next_line(fd, &line) > 0)
	{
		scene->param = ft_split_upd(line, " \t\v\n\r\f");
		if (scene->param[0])
			define_type(scene);
		scene->param = free_2array(scene->param);
		free(line);
		line = NULL;
	}
	close(fd);
	if (scene->res.is_parsed == 0)
		errors_handler(NO_RESOLUTION, scene);
	/* --> parser checker <--*/
	/*
	printf("%d,%d	\n", scene->res.x, scene->res.y);
	printf("%.1f	%d,%d,%d\n", scene->amb.ratio, scene->amb.rgb.r, scene->amb.rgb.g, scene->amb.rgb.b);
	t_camera	*camera;
	while(scene->cam_list)
	{
		camera = scene->cam_list->content;
		printf("%.1f,%.1f,%.1f	", camera->coord.x, camera->coord.y, camera->coord.z);
		printf("%.1f,%.1f,%.1f	", camera->orient.x, camera->orient.y, camera->orient.z);
		printf("%d\n", camera->fov);
		scene->cam_list = scene->cam_list->next;
	}
	t_light		*light;
	while (scene->light_list)
	{
		light = scene->light_list->content;
		printf("%.1f,%.1f,%.1f	", light->coord.x, light->coord.y, light->coord.z);
		printf("%.1f	", light->bright);
		printf("%d,%d,%d\n", light->rgb.r, light->rgb.g, light->rgb.b);
		scene->light_list = scene->light_list->next;
	}
	t_object	*obj;
	while(scene->objs_list)	
	{
		obj = scene->objs_list->content;
		if (obj->id == SPHERE)
		{
			printf("%.1f,%.1f,%.1f	", obj->sphere.coord.x, obj->sphere.coord.y, obj->sphere.coord.z);
			printf("%.1f	", obj->sphere.diam);
			printf("%d,%d,%d\n", obj->sphere.rgb.r, obj->sphere.rgb.g, obj->sphere.rgb.b);
		}
		else if (obj->id == PLANE)
		{
			printf("%.1f,%.1f,%.1f	", obj->plane.coord.x, obj->plane.coord.y, obj->plane.coord.z);
			printf("%.1f,%.1f,%.1f	", obj->plane.orient.x, obj->plane.orient.y, obj->plane.orient.z);
			printf("%d,%d,%d\n", obj->plane.rgb.r, obj->plane.rgb.g, obj->plane.rgb.b);
		}
		else if (obj->id == SQUARE)
		{
			printf("%.1f,%.1f,%.1f	", obj->square.coord.x, obj->square.coord.y, obj->square.coord.z);
			printf("%.1f,%.1f,%.1f	", obj->square.orient.x, obj->square.orient.y, obj->square.orient.z);
			printf("%.1f	", obj->square.size);
			printf("%d,%d,%d\n", obj->square.rgb.r, obj->square.rgb.g, obj->square.rgb.b);
		}
		else if (obj->id == CYLINDER)
		{
			printf("%.1f,%.1f,%.1f	", obj->cylinder.coord.x, obj->cylinder.coord.y, obj->cylinder.coord.z);
			printf("%.1f,%.1f,%.1f	", obj->cylinder.orient.x, obj->cylinder.orient.y, obj->cylinder.orient.z);
			printf("%.1f	", obj->cylinder.diam);
			printf("%.1f	", obj->cylinder.height);
			printf("%d,%d,%d\n", obj->cylinder.rgb.r, obj->cylinder.rgb.g, obj->cylinder.rgb.b);
		}
		else if (obj->id == TRIANGLE)
		{
			printf("%.1f,%.1f,%.1f	", obj->triangle.coord1.x, obj->triangle.coord1.y, obj->triangle.coord1.z);
			printf("%.1f,%.1f,%.1f	", obj->triangle.coord2.x, obj->triangle.coord2.y, obj->triangle.coord2.z);
			printf("%.1f,%.1f,%.1f	", obj->triangle.coord3.x, obj->triangle.coord3.y, obj->triangle.coord3.z);
			printf("%d,%d,%d\n", obj->triangle.rgb.r, obj->triangle.rgb.g, obj->triangle.rgb.b);
		}
		scene->objs_list = scene->objs_list->next;
	}
	*/
}

void	parse_resolution(t_scene *scene)
{
	if ((count_2array(scene->param)) != 3 || is_correct(scene) == 0)
		errors_handler(INVALID_RESOLUTION, scene);
	scene->res.x = ft_atoi(scene->param[1]);
	scene->res.y = ft_atoi(scene->param[2]);
	scene->res.is_parsed = 1;
	if (scene->res.x < 100 || scene->res.y < 100)
		errors_handler(RESOLUTION_IS_SMALL, scene);
	if (scene->res.x > 2560)
		scene->res.x = 2560;
	if (scene->res.y > 1440)
		scene->res.y = 1440;
}

void	parse_ambient(t_scene *scene)
{
	if ((count_2array(scene->param)) != 3 || is_correct(scene) == 0)
		errors_handler(INVALID_AMBIENT, scene);
	scene->amb.ratio = ft_atod(scene->param[1]);
	scene->amb.rgb = parse_rgb(scene->param[2], scene);
	scene->amb.is_parsed = 1;
	if (scene->amb.ratio < 0.0 || scene->amb.ratio > 1.0)
		errors_handler(INVALID_AMBIENT, scene);
}

void	parse_camera(t_scene *scene)
{
	t_camera	*camera;

	if ((count_2array(scene->param)) != 4 || is_correct(scene) == 0)
		errors_handler(INVALID_CAMERA, scene);
	if (!(camera = (t_camera*)malloc(sizeof(t_camera))))
		errors_handler(MALLOC_ERR, scene);
	camera->coord = parse_xyz(scene->param[1], scene);
	camera->orient = parse_xyz(scene->param[2], scene);
	camera->fov = ft_atod(scene->param[3]);
	if (camera->fov < 0 || camera->fov > 180)
		errors_handler(INVALID_CAMERA, scene);
	if (orient_range(camera->orient) == 0)
		errors_handler(INVALID_CAMERA, scene);
	ft_lstadd_back(&(scene->cam_list), ft_lstnew(camera));
}

void	parse_light(t_scene *scene)
{
	t_light		*light;

	if (count_2array(scene->param) != 4 || is_correct(scene) == 0)
		errors_handler(INVALID_LIGHT, scene);
	if (!(light = (t_light*)malloc(sizeof(t_light))))
		errors_handler(MALLOC_ERR, scene);
	light->coord = parse_xyz(scene->param[1], scene);
	light->bright = ft_atod(scene->param[2]);
	light->rgb = parse_rgb(scene->param[3], scene);
	if (light->bright < 0.0 || light->bright > 1.0)
		errors_handler(INVALID_LIGHT, scene);
	ft_lstadd_back(&(scene->light_list), ft_lstnew(light));
}
