/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 17:36:13 by hovalygta         #+#    #+#             */
/*   Updated: 2020/10/03 00:29:37 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include "errors_handler.h"
# include "structures.h"
# include "libft.h"

void    parsing(char *rt_file, t_scene *scene);
void    parse_resolution(t_scene *scene);
void    parse_ambient(t_scene *t_scene);
void    parse_light(t_scene *scene);
void    parse_camera(t_scene *scene);
void    parse_plane(t_scene *scene);
void    parse_sphere(t_scene *scene);
void    parse_square(t_scene *scene);
void    parse_cylinder(t_scene *scene);
void    parse_triangle(t_scene *scene);
char    **free_2array(char **array);
int     count_2array(char **array);
int     is_correct(t_scene *scene);
void    define_type(t_scene *t_scene);
int		rgb_range(t_rgb rgb);

#endif
