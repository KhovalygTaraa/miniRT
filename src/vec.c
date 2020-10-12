/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 22:56:55 by swquinc           #+#    #+#             */
/*   Updated: 2020/10/09 02:02:28 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_xyz	vec_sum(t_xyz vec1, t_xyz vec2)
{
	t_xyz	sum;

	sum.x = vec1.x + vec2.x;
	sum.y = vec1.y + vec2.y;
	sum.z = vec1.z + vec2.z;
	return (sum);
}

t_xyz	vec_sub(t_xyz vec1, t_xyz vec2)
{
	t_xyz	sub;

	sub.x = vec1.x - vec2.x;
	sub.y = vec1.y - vec2.y;
	sub.z = vec1.z - vec2.z;
	return (sub);
}

t_xyz	vec_mpl(t_xyz vec, double mpl)
{
	t_xyz	res;

	res.x = vec.x * mpl;
	res.y = vec.y * mpl;
	res.z = vec.z * mpl;
	return (res);
}

t_xyz	vec_div(t_xyz vec, double div)
{
	t_xyz	res;

	res.x = vec.x / div;
	res.y = vec.y / div;
	res.z = vec.z / div;
	return (res);
}

double	vec_dot(t_xyz vec1, t_xyz vec2)
{
	double	dot;

	dot = (vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z * vec2.z);
	return (dot);
}