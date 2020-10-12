/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 22:31:10 by swquinc           #+#    #+#             */
/*   Updated: 2020/10/12 19:19:57 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		res(t_scene *scene, t_camera *camera, int a, int b)
{

}

static void		draw(t_camera *camera, t_scene *scene)
{

	
}

void	create_camera(t_scene *scene)
{
	t_camera	*camera;
	t_list		*tmp;

	tmp = scene->cam_list;
	while (tmp)
	{
		camera = tmp->content;
		if (!(camera->image.img = mlx_new_image(scene->mlx, scene->res.x, scene->res.y)))
			errors_handler(MLX_NEW_IMAGE_FAIL, scene);
		camera->image.addr = mlx_get_data_addr(camera->image.img,
		&camera->image.bits_per_pixel, &camera->image.line_lenght, &camera->image.endian);
		raytrace(camera, scene);
		if (!scene->camera.image.img)
			scene->camera = *camera;
	//	prepare();
	//	raytracing();
		tmp = tmp->next;
	}
}