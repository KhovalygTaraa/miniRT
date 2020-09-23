/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorsHandler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hovalygtaraa <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 16:44:53 by hovalygta         #+#    #+#             */
/*   Updated: 2020/09/23 19:10:19 by hovalygta        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while(str[i] != 0)
		i++;
	return (i);
}

static void ft_perror(char *error)
{
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
}

static void printError(int error_id)
{
	if (error_id == WRONG_ARGC)
		ft_perror("Wrong number of arguments. Use this forms: ./a.out <arg> or ./a.out <arg1> <arg2>");	
}

void errorsHandler(int error_id, t_scene *scene)
{
	printError(error_id);
//	structFree(scene);
	exit(EXIT_FAILURE);	
}
