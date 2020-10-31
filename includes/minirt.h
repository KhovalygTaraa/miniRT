/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 17:36:13 by swquinc           #+#    #+#             */
/*   Updated: 2020/10/31 23:53:06 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# define SPHERE 0
# define PLANE 1
# define SQUARE 2
# define CYLINDER 3
# define TRIANGLE 4
# define CIRCLE 5
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include "mlx.h"
# include "errors_handler.h"
# include "structures.h"
# include "libft.h"

int			light(t_xyz p, t_xyz n, t_scene *scene, t_rgb rgb);
int			light_color_shadow(t_scene *scene, t_camera *cam, t_xyz ray);
t_rgb		color_bright(t_rgb color, double ratio);
t_rgb		new_color(t_rgb color1, t_rgb color2);
t_rgb		final_color(t_rgb color1, t_rgb color2);
t_object	cpy_obj(t_object *obj);
double		cap(t_plane plane, t_xyz origin, t_xyz ray);
void		create_bmp(t_scene *scene);
void		free_all(t_scene *scene);
void		raytrace(t_camera *camera, t_scene *scene);
void		start_rt(t_scene *scene);
int			sphere(t_scene *scene, t_camera *camera, t_xyz ray, t_sphere sp);
int			plane(t_scene *scene, t_camera *camera, t_xyz ray, t_plane plane);
int			square(t_scene *scene, t_camera *camera, t_xyz ray, t_square sq);
int			triangle(t_scene *scene, t_camera *cam, t_xyz ray, t_triangle tr);
int			cylinder(t_scene *scene, t_camera *cam, t_xyz ray, t_cylinder cy);
int			circle(t_scene *scene, t_camera *camera, t_xyz ray, t_circle cr);
int			selector(t_scene *s, t_camera *cam, t_xyz ray, t_object *object);
void		parsing(char *rt_file, t_scene *scene);
void		parse_resolution(t_scene *scene);
void		parse_ambient(t_scene *scene);
void		parse_light(t_scene *scene);
void		parse_camera(t_scene *scene);
void		parse_plane(t_scene *scene);
void		parse_sphere(t_scene *scene);
void		parse_square(t_scene *scene);
void		parse_cylinder(t_scene *scene);
void		parse_triangle(t_scene *scene);
void		parse_circle(t_scene *scene, t_cylinder cy, double height);
t_rgb		parse_rgb(char *str, t_scene *scene);
t_xyz		parse_xyz(char *str, t_scene *scene);
void		free_all(t_scene *scene);
char		**free_2array(char **array);
int			count_2array(char **array);
int			is_correct(t_scene *scene);
void		define_type(t_scene *scene);
int			rgb_range(t_rgb rgb);
int			orient_range(t_xyz xyz);
void		create_camera(t_scene *scene);
void		switch_camera(t_scene *scene);
void		next_camera(t_scene *scene);
void		prev_camera(t_scene *scene);
void		show_scene(t_scene *scene);
void		my_mlx_pixel_put(t_image *data, int x, int y, int color);
t_xyz		vec_sum(t_xyz vec1, t_xyz vec2);
t_xyz		vec_sub(t_xyz vec1, t_xyz vec2);
t_xyz		vec_mpl(t_xyz vec1, double mpl);
t_xyz		vec_div(t_xyz vec1, double div);
t_xyz		vec_norm(t_xyz vec);
t_xyz		vec_cross(t_xyz vec, t_xyz vec2);
double		vec_smth(t_xyz vec, t_xyz vec2);
double		vec_dot(t_xyz vec1, t_xyz vec2);
double		vec_length(t_xyz vec);

#endif
