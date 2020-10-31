/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 11:22:18 by hovalygtara       #+#    #+#             */
/*   Updated: 2020/10/31 02:46:59 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	**free_2array(char **array)
{
	int		i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
	return (array);
}

void	define_type(t_scene *scene)
{
	if (ft_strncmp(scene->param[0], "R", 2) == 0)
		parse_resolution(scene);
	else if (ft_strncmp(scene->param[0], "A", 2) == 0)
		parse_ambient(scene);
	else if (ft_strncmp(scene->param[0], "c", 2) == 0)
		parse_camera(scene);
	else if (ft_strncmp(scene->param[0], "l", 2) == 0)
		parse_light(scene);
	else if (ft_strncmp(scene->param[0], "sp", 3) == 0)
		parse_sphere(scene);
	else if (ft_strncmp(scene->param[0], "pl", 3) == 0)
		parse_plane(scene);
	else if (ft_strncmp(scene->param[0], "cy", 3) == 0)
		parse_cylinder(scene);
	else if (ft_strncmp(scene->param[0], "sq", 3) == 0)
		parse_square(scene);
	else if (ft_strncmp(scene->param[0], "tr", 3) == 0)
		parse_triangle(scene);
	else
		return ;
}

int		count_2array(char **array)
{
	int		i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}

int		is_correct(t_scene *scene)
{
	int		i;
	int		a;
	int		b;

	i = 1;
	while (scene->param[i] != NULL)
	{
		b = 0;
		a = 0;
		while (scene->param[i][a] != '\0')
		{
			if ((!ft_isdigit(scene->param[i][a]) && scene->param[i][a] != ',' &&
			scene->param[i][a] != '.' && scene->param[i][a] != '-'))
				return (0);
			if (scene->param[i][a] == ',')
				b++;
			a++;
		}
		if (b == 1 || b >= 3)
			return (0);
		i++;
	}
	return (1);
}

int		rgb_range(t_rgb rgb)
{
	int		i;

	i = 1;
	if (rgb.r < 0 || rgb.r > 1)
		i = 0;
	if (rgb.g < 0 || rgb.g > 1)
		i = 0;
	if (rgb.b < 0 || rgb.b > 1)
		i = 0;
	return (i);
}
