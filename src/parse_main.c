/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 17:55:08 by hovalygtara       #+#    #+#             */
/*   Updated: 2020/10/04 01:09:16 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void    parsing(char *rt_file, t_scene *scene)
{
    int     fd;
    char    *line;
    int     i;

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
}

void    parse_resolution(t_scene *scene)
{
    if ((count_2array(scene->param)) != 3 || is_correct(scene) == 0)
        errors_handler(INVALID_RESOLUTION, scene);
    scene->res.x = ft_atoi(scene->param[1]);
    scene->res.y = ft_atoi(scene->param[2]);
    scene->res.is_parsed = 1;
    if (scene->res.x < 100  || scene->res.y < 100)
        errors_handler(RESOLUTION_IS_SMALL, scene);
    if (scene->res.x > 2560)
        scene->res.x = 2560;
    if (scene->res.y > 1440)
        scene->res.y = 1440;
}

void    parse_ambient(t_scene *scene)
{
	char	**array;

    if ((count_2array(scene->param)) != 3 || is_correct(scene) == 0)
        errors_handler(INVALID_AMBIENT, scene);
	scene->amb.ratio = ft_atof(scene->param[1]);
	array = ft_split(scene->param[2], ',');
	scene->amb.rgb.r = ft_atoi(array[0]);
	scene->amb.rgb.g = ft_atoi(array[1]);
	scene->amb.rgb.b = ft_atoi(array[2]);
	scene->amb.is_parsed = 1;
	if (!rgb_range(scene->amb.rgb))
		errors_handler(INVALID_AMBIENT, scene);
	if (scene->amb.ratio < 0.0 || scene->amb.ratio > 1.0 )
		errors_handler(INVALID_AMBIENT,scene);
}

void    parse_camera(t_scene *scene)
{
	
}

void    parse_light(t_scene *scene)
{

}
