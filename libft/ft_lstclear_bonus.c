/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:53:09 by seunlee2          #+#    #+#             */
/*   Updated: 2023/03/24 15:35:38 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	**l;
	t_list	*l_n;

	if (!lst || !(*del))
		return ;
	l = lst;
	while (*lst)
	{
		if (!(*lst)->next)
		{
			(*del)((*lst)->content);
			free((*lst));
			break ;
		}
		l_n = (*lst)->next;
		(*del)((*lst)->content);
		free((*lst));
		(*lst) = l_n;
	}
	*l = NULL;
}
