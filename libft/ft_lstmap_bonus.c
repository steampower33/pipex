/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:13:11 by seunlee2          #+#    #+#             */
/*   Updated: 2023/03/24 15:29:13 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*res;
	void	*c;

	res = NULL;
	while (lst)
	{
		c = (*f)(lst->content);
		new = ft_lstnew(c);
		if (!new)
		{
			(*del)(c);
			ft_lstclear(&new, (*del));
			break ;
		}
		ft_lstadd_back(&res, new);
		lst = lst->next;
	}
	return (res);
}
