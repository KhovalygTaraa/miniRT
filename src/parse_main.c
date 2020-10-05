/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 17:55:08 by hovalygtara       #+#    #+#             */
/*   Updated: 2020/10/05 21:43:35 by swquinc          ###   ########.fr       */
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

	printf("%d,%d\n", scene->res.x, scene->res.y);
	printf("%d,%d,%d	%.2f\n", scene->amb.rgb.r, scene->amb.rgb.g, scene->amb.rgb.b, scene->amb.ratio);
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
	char	**array;

	if ((count_2array(scene->param)) != 3 || is_correct(scene) == 0)
		errors_handler(INVALID_AMBIENT, scene);
	scene->amb.ratio = ft_atof(scene->param[1]);
	if (!(array = ft_split(scene->param[2], ',')))
		errors_handler(MALLOC_ERR, scene);
	scene->amb.rgb.r = ft_atoi(array[0]);
	scene->amb.rgb.g = ft_atoi(array[1]);
	scene->amb.rgb.b = ft_atoi(array[2]);
	scene->amb.is_parsed = 1;
	free_2array(array);
	if (!rgb_range(scene->amb.rgb))
		errors_handler(INVALID_AMBIENT, scene);
	if (scene->amb.ratio < 0.0 || scene->amb.ratio > 1.0)
		errors_handler(INVALID_AMBIENT, scene);
}

void	parse_camera(t_scene *scene)
{
	t_camera	*camera;
	char		**coord;
	char		**orient;

	if ((count_2array(scene->param)) != 4 || is_correct(scene) == 0)
		errors_handler(INVALID_CAMERA, scene);
	if (!(camera = (t_camera*)malloc(sizeof(t_camera))))
		errors_handler(MALLOC_ERR, scene);
	if (!(coord = ft_split(scene->param[1], ',')))
		errors_handler(MALLOC_ERR, scene);
	if (!(orient = ft_split(scene->param[2], ',')))
		errors_handler(MALLOC_ERR, scene);
	camera->coord.x = ft_atof(coord[0]);
	camera->coord.y = ft_atof(coord[1]);
	camera->coord.z = ft_atof(coord[2]);
	camera->orient.x = ft_atof(orient[0]);
	camera->orient.y = ft_atof(orient[1]);
	camera->orient.z = ft_atof(orient[2]);
	camera->fov = ft_atoi(scene->param[3]);
	free_2array(coord);
	free_2array(orient);
	if (camera->fov < 0 || camera->fov > 180 ||
	orient_range(camera->orient) == 0)
		errors_handler(INVALID_CAMERA, scene);
	ft_lstadd_back(&(scene->cam_list), ft_lstnew(camera));
}

void	parse_light(t_scene *scene)
{
	t_light		*light;
	char		**coord;
	char		**rgb;

	if (count_2array(scene->param) != 4 || is_correct(scene) == 0)
		errors_handler(INVALID_LIGHT, scene);
	if (!(light = (t_light*)malloc(sizeof(t_light))))
		errors_handler(MALLOC_ERR, scene);
	if (!(coord = ft_split(scene->param[1], ',')))
		errors_handler(MALLOC_ERR, scene);
	if (!(rgb = ft_split(scene->param[3], ',')))
		errors_handler(MALLOC_ERR, scene);
	light->coord.x = ft_atof(coord[0]);
	light->coord.y = ft_atof(coord[1]);
	light->coord.z = ft_atof(coord[2]);
	light->rgb.r = ft_atoi(rgb[0]);
	light->rgb.g = ft_atoi(rgb[1]);
	light->rgb.b = ft_atoi(rgb[2]);
	light->bright = ft_atof(scene->param[2]);
	free_2array(coord);
	free_2array(rgb);
	if (light->bright < 0.0 || light->bright > 1.0 ||
	rgb_range(light->rgb) == 0)
		errors_handler(INVALID_LIGHT, scene);
	ft_lstadd_back(&(scene->light_list), ft_lstnew(light));
}
