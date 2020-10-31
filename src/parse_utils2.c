/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 19:20:38 by swquinc           #+#    #+#             */
/*   Updated: 2020/10/31 02:50:17 by swquinc          ###   ########.fr       */
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

t_rgb		parse_rgb(char *str, t_scene *scene)
{
	t_rgb	color;
	char	**rgb;
	int		i;

	if (!(rgb = ft_split(str, ',')))
		errors_handler(MALLOC_ERR, scene);
	if((i = count_2array(rgb)) != 3)
		errors_handler(WRONG_PARAM, scene);
	color.r = ft_atod(rgb[0]) / 255;
	color.g = ft_atod(rgb[1]) / 255;
	color.b = ft_atod(rgb[2]) / 255;
	free_2array(rgb);
	if (rgb_range(color) == 0)
		errors_handler(INVALID_RGB_RANGE, scene);
	return (color);
}

t_xyz	parse_xyz(char *str, t_scene *scene)
{
	t_xyz	xyz;
	char	**array;
	int		i;

	if (!(array = ft_split(str, ',')))
		errors_handler(MALLOC_ERR, scene);
	if((i = count_2array(array)) != 3)
		errors_handler(WRONG_PARAM, scene);
	xyz.x = ft_atod(array[0]);
	xyz.y = ft_atod(array[1]);
	xyz.z = ft_atod(array[2]);
	free_2array(array);
	return (xyz);
}

void	parse_circle(t_scene *scene, t_cylinder cy, double height)
{
	t_object	*obj;

	if (!(obj = (t_object*)malloc(sizeof(t_object))))
		errors_handler(MALLOC_ERR, scene);
	obj->id = CIRCLE;
	obj->circle.coord = vec_sum(cy.coord, vec_mpl(vec_norm(cy.orient), height));
	obj->circle.orient = cy.orient;
	obj->circle.diam = cy.diam;
	obj->circle.rgb = cy.rgb;
	ft_lstadd_back(&(scene->objs_list), ft_lstnew(obj));
}
