/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:05:11 by seunlee2          #+#    #+#             */
/*   Updated: 2023/03/24 15:26:47 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*l;

	l = lst;
	while (lst)
	{
		if (!lst->next)
		{
			(*f)(lst->content);
			break ;
		}
		(*f)(lst->content);
		lst = lst->next;
	}
	lst = l;
}
