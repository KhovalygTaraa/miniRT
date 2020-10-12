/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 00:07:04 by swquinc           #+#    #+#             */
/*   Updated: 2020/10/12 18:23:35 by swquinc          ###   ########.fr       */
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
	double	inversion;

	inversion = 1 / vec_length(vec);
	vec = vec_mpl(vec, inversion);
	return (vec);
}