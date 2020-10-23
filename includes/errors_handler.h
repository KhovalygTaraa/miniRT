/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handler.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:20:58 by hovalygta         #+#    #+#             */
/*   Updated: 2020/10/22 12:53:17 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_HANDLER_H
# define ERRORS_HANDLER_H
# define WRONG_ARGS 0
# define WRONG_EXTENSION 1
# define CANNOT_OPEN_FILE 2
# define RESOLUTION_IS_SMALL 3
# define MALLOC_ERR 4
# define INVALID_RESOLUTION 5
# define INVALID_AMBIENT 6
# define INVALID_CAMERA 7
# define INVALID_LIGHT 8
# define INVALID_SPHERE 9
# define INVALID_PLANE 10
# define INVALID_SQUARE 11
# define INVALID_CYLINDER 12
# define INVALID_TRIANGLE 13
# define NO_RESOLUTION 14
# define MINILIBX_FAIL 15
# define MLX_NEW_IMAGE_FAIL 16
# define WRONG_PARAM 17
# define INVALID_RGB_RANGE 18
# include "structures.h"

void	errors_handler(int error_id, t_scene *scene);

#endif
