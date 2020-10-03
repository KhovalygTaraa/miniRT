/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 17:36:13 by hovalygta         #+#    #+#             */
/*   Updated: 2020/10/03 23:27:00 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct		s_rgb
{
	int		r;
	int		g;
	int		b;
}					t_rgb;

typedef struct		s_vec
{
	float		x;
	float		y;
	float		z;
}					t_vec;

typedef struct		s_resolution
{
	int		x;
	int		y;
	int		is_parsed;
}					t_resolution;

typedef struct		s_ambient
{
	float	ratio;
	t_rgb	rgb;
	int		is_parsed;
}					t_ambient;

typedef struct		s_camera
{
	int					num;
	int					fov;
	t_vec				view;
	t_vec				orient;
	struct s_camera		*next;
}					t_camera;

typedef struct		s_light
{
}					t_light;

typedef struct		s_sphere
{
}					t_sphere;

typedef struct		s_plane
{
}					t_plane;

typedef struct		s_square 
{
}					t_square;


typedef struct		s_cylinder
{
}					t_cylinder;

typedef struct		s_triangle
{
}					t_triangle;


typedef struct		s_scene
{
	t_camera			*cameras;
	t_resolution		res;
	t_ambient			amb;
	int					save;
	char				**param;
}					t_scene;

#endif
