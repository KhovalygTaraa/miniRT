/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hovalygtaraa <hovalygtaraa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 17:55:08 by hovalygtara       #+#    #+#             */
/*   Updated: 2020/10/02 21:34:52 by hovalygtara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void    parsing(char *rt_file, t_scene *scene)
{
    int     fd;
    char    *line;
    int     i;

    if ((fd = open(rt_file, O_RDONLY)) < 0)
        errorsHandler(CANNOT_OPEN_FILE, scene);
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
        errorsHandler(INVALID_RESOLUTION, scene);
    scene->res.x = ft_atoi(scene->param[1]);
    scene->res.y = ft_atoi(scene->param[2]);
    scene->res.is_parsed = 1;
    if (scene->res.x < 100  || scene->res.y < 100)
        errorsHandler(RESOLUTION_IS_SMALL, scene);
    if (scene->res.x > 2560)
        scene->res.x = 2560;
    if (scene->res.y > 1440)
        scene->res.y = 1440;
}

void    parse_ambient(t_scene *scene)
{
    if ((count_2array(scene->param)) != 3 || is_correct(scene) == 0)
        errorsHandler(INVALID_AMBIENT, scene);
    // scene->amb.ratio = 
}

void    parse_light(t_scene *scene)
{
}

void    parse_camera(t_scene *scene)
{
}