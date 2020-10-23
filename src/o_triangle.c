/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_triangle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 01:04:28 by swquinc           #+#    #+#             */
/*   Updated: 2020/10/23 18:24:48 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		triangle(t_scene *scene, t_camera *cam, t_xyz ray, t_triangle tr)
{
	double	x;
	double	y;
	double	z;


	x = tr.coord1.x * ray.x + tr.coord2.x * ray.x + tr.coord3.x * ray.x;
	y = tr.coord1.y * ray.y + tr.coord2.y * ray.y + tr.coord3.y * ray.y;
	z = tr.coord1.z * ray.z + tr.coord2.z * ray.z + tr.coord3.z * ray.z;

	if (x >= 0 && y >= 0 && z >= 0)
		return (0255000000);
	return (0000);
}