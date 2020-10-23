/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 01:51:05 by swquinc           #+#    #+#             */
/*   Updated: 2020/10/22 22:38:48 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		light(t_xyz p, t_xyz n, t_scene *scene, t_rgb rgb)
{
	t_light		*light;
	t_xyz		l;
	double		dot;
	double		i;
	t_rgb		color;

	i = 0;
	light = scene->light_list->content;
	l = vec_sub(light->coord, p);
	dot = vec_dot(n, l);
	i = i + scene->amb.ratio;
	if (dot > 0)
		i = i + (light->bright * dot / (vec_length(n) * vec_length(l)));
	color.r = rgb.r * i;
	color.g = rgb.g * i;
	color.b = rgb.b * i;
	return (0 << 24 | color.r << 16 | color.g << 8 | color.b);
}