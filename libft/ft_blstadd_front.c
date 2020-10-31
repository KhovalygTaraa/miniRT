/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swquinc <swquinc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 23:46:19 by swquinc           #+#    #+#             */
/*   Updated: 2020/10/29 09:06:48 by swquinc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_blstadd_front(t_bilist **lst, t_bilist *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	new->next->prev = new;
	*lst = new;
}