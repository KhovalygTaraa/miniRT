/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 19:20:38 by swquinc           #+#    #+#             */
/*   Updated: 2020/10/07 01:01:49 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		orient_range(t_xyz xyz)
{
	int		i;

	i = 1;
	if (xyz.x < -1.0 || xyz.x > 1.0)
		i = 0;
	if (xyz.y < -1.0 || xyz.y > 1.0)
		i = 0;
	if (xyz.z < -1.0 || xyz.z > 1.0)
		i = 0;
	return (i);
}

t_rgb	parse_rgb(char *str, t_scene *scene)
{
	t_rgb	color;
	char	**rgb;

	if (!(rgb = ft_split(str, ',')))
		errors_handler(MALLOC_ERR, scene);
	color.r = ft_atoi(rgb[0]);
	color.g = ft_atoi(rgb[1]);
	color.b = ft_atoi(rgb[2]);
	free_2array(rgb);
	return (color);
}

t_xyz	parse_xyz(char *str, t_scene *scene)
{
	t_xyz	xyz;
	char	**array;

	if (!(array = ft_split(str, ',')))
		errors_handler(MALLOC_ERR, scene);
	xyz.x = ft_atod(array[0]);
	xyz.y = ft_atod(array[1]);
	xyz.z = ft_atod(array[2]);
	free_2array(array);
	return (xyz);
}
