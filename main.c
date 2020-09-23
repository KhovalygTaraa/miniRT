/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hovalygtaraa <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 16:15:19 by hovalygta         #+#    #+#             */
/*   Updated: 2020/09/23 19:11:31 by hovalygta        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	static	t_scene scene;
	int checker;

	if (argc != 2 && argc != 3)
		errorsHandler(WRONG_ARGC, &scene);
/*	parsing(checker, argv[1], scene);
	if (argc == 2)
		showScene(checker, scene);
	else if (argc == 3)
		if (checker == 1)
			screenShot(scene);
		else 
			error();
	structFree(scene);
	scene = NULL; */
	return (0);
}
