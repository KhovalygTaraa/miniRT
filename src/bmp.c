/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:32:08 by swquinc           #+#    #+#             */
/*   Updated: 2020/10/31 18:40:26 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		bitmap_file_data(t_scene *scene, int size, int fd)
{
	unsigned char	*data;
	int				file_size;

	if (!(data = ft_calloc(14, sizeof(unsigned char))))
		errors_handler(MALLOC_ERR, scene);
	file_size = 54 + (scene->camera.image.bits_per_pixel / 8 * scene->res.x + size) * scene->res.y;
	data[0] = (unsigned char)('B');
	data[1] = (unsigned char)('M');
	data[2] = (unsigned char)(file_size);
	data[3] = (unsigned char)(file_size >> 8);
	data[4] = (unsigned char)(file_size >> 16);
	data[5] = (unsigned char)(file_size >> 24);
	data[10] = (unsigned char)(54);
	write(fd, data, 14);
	free(data);
	data = NULL;
}

static void		bitmap_image_data(t_scene *scene, int fd)
{
	unsigned char	*data;

	if (!(data = ft_calloc(40, sizeof(unsigned char))))
		errors_handler(MALLOC_ERR, scene);
	data[0] = (unsigned char)(40);
	data[4] = (unsigned char)(scene->res.x);
	data[5] = (unsigned char)(scene->res.x >> 8);
	data[6] = (unsigned char)(scene->res.x >> 16);
	data[7] = (unsigned char)(scene->res.x >> 24);
	data[8] = (unsigned char)(scene->res.y);
	data[9] = (unsigned char)(scene->res.y >> 8);
	data[10] = (unsigned char)(scene->res.y >> 16);
	data[11] = (unsigned char)(scene->res.y >> 24);
	data[12] = (unsigned char)(1);
	data[14] = (unsigned char)(scene->camera.image.bits_per_pixel);
	write(fd, data, 40);
	free(data);
	data = NULL;
}

void	create_bmp(t_scene *scene)
{
	int		fd;
	int		size;
	int		i;
	unsigned char	*data;

	if (!(data = ft_calloc(4, sizeof(unsigned char))))
		errors_handler(MALLOC_ERR, scene);
	i = scene->res.y;
	if (!(fd = open("save.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0666)))
		errors_handler(CANNOT_OPEN_FILE, scene);
	size = (4 - (scene->res.x * scene->camera.image.bits_per_pixel / 8) % 4) % 4;
	bitmap_file_data(scene, size, fd);
	bitmap_image_data(scene, fd);
	while (i >= 0)
	{
		write(fd, scene->camera.image.addr +
		(i * scene->res.x * scene->camera.image.bits_per_pixel / 8),
		scene->camera.image.line_lenght);
		write(fd, data, size);
		i--;
	}
	free(data);
	close(fd);
}