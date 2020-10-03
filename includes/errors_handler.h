/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handler.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:20:58 by hovalygta         #+#    #+#             */
/*   Updated: 2020/10/02 23:02:27 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_HANDLER_H
# define ERRORS_HANDLER_H
# define WRONG_ARGS 0
# define WRONG_EXTENSION 1
# define CANNOT_OPEN_FILE 2
# define INVALID_RESOLUTION 3
# define RESOLUTION_IS_SMALL 4
# define INVALID_AMBIENT 5
# include "structures.h"

void	errors_handler(int error_id, t_scene *scene);

#endif
