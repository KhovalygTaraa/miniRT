/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 16:15:19 by hovalygta         #+#    #+#             */
/*   Updated: 2020/10/31 18:41:39 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


static int	kill(t_scene *scene)
{
	mlx_destroy_window(scene->mlx, scene->win_ptr);
	free_all(scene);
	exit(EXIT_SUCCESS);
}

static int	cam_switch(int key, t_scene *scene)
{
	if (key == 53)
		kill(scene);
	else if (key == 124)
		next_camera(scene);
	else if (key == 123)
		prev_camera(scene);
	mlx_put_image_to_window(scene->mlx, scene->win_ptr, scene->camera.image.img, 0, 0);
	return (0);
}

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
void	start_rt(t_scene *scene)
{
	if(!(scene->mlx = mlx_init()))
		errors_handler(MINILIBX_FAIL, scene);
	scene->win_ptr = mlx_new_window(scene->mlx, scene->res.x, scene->res.y, "miniRT");
	create_camera(scene);
	if (scene->save)
	{
		create_bmp(scene);
		free_all(scene);
		exit(EXIT_SUCCESS);
	}
	mlx_hook(scene->win_ptr, 17, 0, kill, scene);
	mlx_key_hook(scene->win_ptr, cam_switch, scene);
	mlx_put_image_to_window(scene->mlx, scene->win_ptr, scene->camera.image.img, 0, 0);
	mlx_loop(scene->mlx);
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
	free_all(&scene);
	return (0);
}
