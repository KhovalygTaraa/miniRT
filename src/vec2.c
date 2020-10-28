/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 00:07:04 by swquinc           #+#    #+#             */
/*   Updated: 2020/10/24 01:27:47 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	vec_length(t_xyz vec)
{
	double	length;
	
	length = sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));
	return (length);
}

t_xyz	vec_norm(t_xyz	vec)
{
	double inversion;
	double lenght;

	lenght = vec_length(vec);
	if (lenght == 0)
		return ((t_xyz){0,0,0});
	inversion = 1 / lenght;
	vec = vec_mpl(vec, inversion);
	return (vec);
}

double vec_smth(t_xyz vec, t_xyz vec2)
{
	return ((vec.x * vec2.x) - (vec.y * vec2.y) - (vec.z * vec2.z));
}

t_xyz	vec_cross(t_xyz vec, t_xyz vec2)
{
	t_xyz	res;
	res.x = vec.y * vec2.z - vec2.y * vec.z;
	res.y = vec.z * vec2.x - vec2.z * vec.x;
	res.z = vec.x * vec2.y - vec2.x * vec.y;
	return (res);
}