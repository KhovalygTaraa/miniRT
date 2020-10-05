/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 16:15:19 by hovalygta         #+#    #+#             */
/*   Updated: 2020/10/04 20:34:41 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_scene scene;
	char	*rt;

	ft_bzero(&scene, sizeof(t_scene));
	if ((argc != 2 && argc != 3) ||
	(argc == 3 && (ft_strncmp(argv[2], "--save", 6) != 0)))
		errors_handler(WRONG_ARGS, &scene);
	rt = argv[1] + ft_strlen(argv[1]) - 3;
	if (ft_strncmp(rt, ".rt", 3) != 0)
		errors_handler(WRONG_EXTENSION, &scene);
	if (argc == 3)
		scene.save = 1;
	parsing(argv[1], &scene);
//	showScene();
	return (0);
}
