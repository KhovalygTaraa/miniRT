/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 16:44:53 by hovalygta         #+#    #+#             */
/*   Updated: 2020/10/02 23:04:54 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		ft_perror(char *error)
{
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
}

static void		print_error(int error_id)
{
	if (error_id == WRONG_ARGS)
		ft_perror("Wrong arguments. Use form: a.out <*.rt> or a.out <*.rt> <--save>");
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
}

void		errors_handler(int error_id, t_scene *scene)
{
	print_error(error_id);
	//structFree(scene);
	exit(EXIT_FAILURE);
}
