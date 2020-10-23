/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 16:44:53 by hovalygta         #+#    #+#             */
/*   Updated: 2020/10/22 12:54:18 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		ft_perror(char *error)
{
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
}

static void		print_error2(int error_id)
{
	if (error_id == INVALID_SQUARE)
		ft_perror("Invalid square, please check parameters!");
	else if (error_id == INVALID_CYLINDER)
		ft_perror("Invalid cylinder, please check parameters!");
	else if (error_id == INVALID_TRIANGLE)
		ft_perror("Invalid triangle, please check parameters!");
	else if (error_id == NO_RESOLUTION)
		ft_perror("Resolution does not exist, you should add!");
	else if (error_id == MINILIBX_FAIL)
		ft_perror("Minilibx initialization fail:(");
	else if (error_id == MLX_NEW_IMAGE_FAIL)
		ft_perror("Mlx new image initialization fail:(");
	else if (error_id == WRONG_PARAM)
		ft_perror("Wrong params, please check your .rt file");
	else if (error_id == INVALID_RGB_RANGE)
		ft_perror("Wrong RGB");
	else 
		return ;
}

static void		print_error(int error_id)
{
	if (error_id == WRONG_ARGS)
		ft_perror("Wrong arguments. Use form: somefile.rt --save");
	else if (error_id == WRONG_EXTENSION)
		ft_perror("Wrong extension of rt file. Extension should be \".rt\"");
	else if (error_id == CANNOT_OPEN_FILE)
		perror("FAIL");
	else if (error_id == INVALID_RESOLUTION)
		ft_perror("Invalid resolution, please check parameters!");
	else if (error_id == RESOLUTION_IS_SMALL)
		ft_perror("Resolution size is very small! Put size more than 100");
	else if (error_id == INVALID_AMBIENT)
		ft_perror("Invalid ambient, please check parameters!");
	else if (error_id == MALLOC_ERR)
		perror("Malloc error");
	else if (error_id == INVALID_CAMERA)
		ft_perror("Invalid camera, please check parameters!");
	else if (error_id == INVALID_LIGHT)
		ft_perror("Invalid light, please check parameters!");
	else if (error_id == INVALID_SPHERE)
		ft_perror("Invalid sphere, please check parameters!");
	else if (error_id == INVALID_PLANE)
		ft_perror("Invalid plane, please check parameters!");
	else
		print_error2(error_id);
}

void		errors_handler(int error_id, t_scene *scene)
{
	print_error(error_id);
	//structFree(scene);
	exit(EXIT_FAILURE);
}
