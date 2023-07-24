/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:54:49 by seunlee2          #+#    #+#             */
/*   Updated: 2023/03/24 18:16:49 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*l;

	if (!new)
		return ;
	if (!(*lst) && new)
	{
		(*lst) = new;
		return ;
	}
	l = *lst;
	while ((*lst)->next)
		(*lst) = (*lst)->next;
	(*lst)->next = new;
	*lst = l;
}
