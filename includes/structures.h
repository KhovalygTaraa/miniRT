/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 17:36:13 by hovalygta         #+#    #+#             */
/*   Updated: 2020/10/31 23:48:33 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# include "libft.h"

typedef struct		s_rgb
{
	double				r;
	double				g;
	double				b;
}					t_rgb;

typedef struct		s_xyz
{
	double			x;
	double			y;
	double			z;
}					t_xyz;

typedef struct		s_mhave
{
	double			dist;
	double			dist2;
	int				color;
	int				is_i;
	t_rgb			cur;
	t_rgb			real;
}					t_mhave;

typedef struct		s_image
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_lenght;
	int				endian;
}					t_image;

typedef struct		s_resolution
{
	int				x;
	int				y;
	int				is_parsed;
}					t_resolution;

typedef struct		s_ambient
{
	double			ratio;
	t_rgb			rgb;
	int				is_parsed;
}					t_ambient;

typedef struct		s_camera
{
	t_xyz			coord;
	t_xyz			orient;
	int				fov;
	t_image			image;
}					t_camera;

typedef struct		s_light
{
	t_xyz			coord;
	double			bright;
	t_rgb			rgb;
}					t_light;

typedef struct		s_sphere
{
	t_xyz			coord;
	double			diam;
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
	double			size;
	t_rgb			rgb;
}					t_square;

typedef struct		s_cylinder
{
	t_xyz			coord;
	t_xyz			orient;
	double			diam;
	double			height;
	t_rgb			rgb;
}					t_cylinder;

typedef struct		s_triangle
{
	t_xyz			coord1;
	t_xyz			coord2;
	t_xyz			coord3;
	t_rgb			rgb;
}					t_triangle;

typedef struct		s_circle
{
	t_xyz			coord;
	t_xyz			orient;
	double			diam;
	t_rgb			rgb;
}					t_circle;

typedef struct		s_object
{
	int			id;
	t_sphere	sphere;
	t_plane		plane;
	t_square	square;
	t_cylinder	cylinder;
	t_triangle	triangle;
	t_circle	circle;

}					t_object;

typedef struct		s_scene
{
	t_bilist		*cam_list;
	t_list			*light_list;
	t_list			*objs_list;
	t_object		obj;
	t_resolution	res;
	t_ambient		amb;
	t_camera		camera;
	t_mhave			mhave;
	void			*mlx;
	void			*win_ptr;
	int				save;
	char			**param;
}					t_scene;

#endif
