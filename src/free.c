/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:24:51 by swquinc           #+#    #+#             */
/*   Updated: 2020/11/01 00:45:22 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		free_list(t_list *list)
{
	t_list		*tmp;

	while (list)
	{
		free(list->content);
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

static void		free_bilist(t_bilist *list)
{
	t_bilist	*tmp;

	while (list)
	{
		free(list->content);
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

void			free_all(t_scene *scene)
{
	free_list(scene->objs_list);
	free_bilist(scene->cam_list);
	free_list(scene->light_list);
}
