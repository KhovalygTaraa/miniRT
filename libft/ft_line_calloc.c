/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 09:55:46 by hovalygta         #+#    #+#             */
/*   Updated: 2020/10/02 22:42:52 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_line_calloc(size_t count, size_t size)
{
	size_t			a;
	unsigned char	*b;

	a = (count * size);
	if (!(b = malloc(a + 1)))
		return (NULL);
	b[a] = '\0';
	return (b);
}
