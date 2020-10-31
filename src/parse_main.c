/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 17:55:08 by hovalygtara       #+#    #+#             */
/*   Updated: 2020/11/01 01:29:35 by hovalygta        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parsing(char *rt_file, t_scene *scene)
{
	int		fd;
	char	*line;

	line = NULL;
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
	free(line);
	close(fd);
	if (scene->res.is_parsed == 0)
		errors_handler(NO_RESOLUTION, scene);
	if (scene->amb.is_parsed == 0)
		errors_handler(NO_AMBIENT, scene);
	if (scene->cam_list == NULL)
		errors_handler(NO_CAMERA, scene);
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
	ft_blstadd_back(&(scene->cam_list), ft_blstnew(camera));
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
