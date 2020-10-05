/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 17:36:13 by hovalygta         #+#    #+#             */
/*   Updated: 2020/10/05 23:49:13 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# include "libft.h"

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct		s_xyz
{
	float			x;
	float			y;
	float			z;
}					t_xyz;

typedef struct		s_resolution
{
	int				x;
	int				y;
	int				is_parsed;
}					t_resolution;

typedef struct		s_ambient
{
	float			ratio;
	t_rgb			rgb;
	int				is_parsed;
}					t_ambient;

typedef struct		s_camera
{
	t_xyz			coord;
	t_xyz			orient;
	int				fov;
}					t_camera;

typedef struct		s_light
{
	t_xyz			coord;
	float			bright;
	t_rgb			rgb;
}					t_light;

typedef struct		s_sphere
{
	t_xyz			coord;
	float			diam;
	t_rgb			rgb;
}					t_sphere;

typedef struct		s_plane
{
	t_xyz			coord;
	t_xyz			orient;
	t_rgb			rgb;
}					t_plane;

typedef struct		s_square
{
	t_xyz			coord;
	t_xyz			orient;
	float			size;
	t_rgb			rgb;
}					t_square;

typedef struct		s_cylinder
{
	t_xyz			coord;
	t_xyz			orient;
	float			diam;
	float			height;
	t_rgb			rgb;
}					t_cylinder;

typedef struct		s_triangle
{
	t_xyz			coord1;
	t_xyz			coord2;
	t_xyz			coord3;
	t_rgb			rgb;
}					t_triangle;

typedef struct		s_object
{
	int			id;
	t_sphere	sphere;
	t_plane		plane;
	t_square	square;
	t_cylinder	cylinder;
	t_triangle	triangle;

}					t_object;

typedef struct		s_scene
{
	t_list			*cam_list;
	t_list			*light_list;
	t_list			*objs_list;
	t_resolution	res;
	t_ambient		amb;
	int				save;
	char			**param;
}					t_scene;

#endif
