/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 18:16:45 by swquinc           #+#    #+#             */
/*   Updated: 2020/10/28 02:55:22 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb	color_bright(t_rgb color, double ratio)
{
	color.r = color.r * ratio;
	color.g = color.g * ratio;
	color.b = color.b * ratio;
	return (color);
}

t_rgb	new_color(t_rgb color1, t_rgb color2)
{
	t_rgb	color;

	color.r = color1.r * color2.r;
	color.g = color1.g * color2.g;
	color.b = color1.b * color2.b;
	return (color);
}

t_rgb	final_color(t_rgb color1, t_rgb color2)
{
	t_rgb	color;

	if((color.r = color1.r + color2.r) > 255)
		color.r = 255;
	if((color.g = color1.g + color2.g) > 255)
		color.g = 255;
	if((color.b = color1.b + color2.b) > 255)
		color.b = 255;
	return (color);
}

t_object	cpy_obj(t_object *obj)
{
	t_object obj2;

	obj2.id = obj->id;
	obj2.circle = obj->circle;
	obj2.triangle = obj->triangle;
	obj2.cylinder = obj->cylinder;
	obj2.square = obj->square;
	obj2.plane = obj->plane;
	obj2.sphere = obj->sphere;
	return (obj2);
}