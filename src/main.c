/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 16:15:19 by hovalygta         #+#    #+#             */
/*   Updated: 2020/10/12 15:39:29 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	kill(t_scene *scene)
{
	mlx_destroy_window(scene->mlx, scene->win_ptr);
	exit(0);
}

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
void	start_rt(t_scene *scene)
{
	int x;
	int y;

	if(!(scene->mlx = mlx_init()))
		errors_handler(MINILIBX_FAIL, scene);
	scene->win_ptr = mlx_new_window(scene->mlx, scene->res.x, scene->res.y, "miniRT");
	create_camera(scene);

	x = scene->res.x;
	y = scene->res.y;
	while (x != 0)
	{
		x--;
	}
	mlx_put_image_to_window(scene->mlx, scene->win_ptr, scene->camera.image.img, 0, 0);
	mlx_hook(scene->win_ptr, 17, 0, kill, scene);
	mlx_loop(scene->mlx);
//	switch_camera(scene);
//	show_scene(scene);
}

int		main(int argc, char **argv)
{
	t_scene		scene;
	char		*rt;

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
	start_rt(&scene);
	return (1);
}
