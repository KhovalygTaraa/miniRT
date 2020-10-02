/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hovalygtaraa <hovalygtaraa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 17:36:13 by hovalygta         #+#    #+#             */
/*   Updated: 2020/10/02 21:34:34 by hovalygtara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct		s_rgb
{
	float	r;
	float	g;
	float	b;
}					t_rgb;

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
	t_resolution		res;
	t_ambient			amb;
	int					save;
	char				**param;
}					t_scene;

#endif
