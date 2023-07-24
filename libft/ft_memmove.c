/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:12:57 by seunlee2          #+#    #+#             */
/*   Updated: 2023/03/23 14:40:30 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			idx;

	if (dst == 0 && src == 0)
		return (dst);
	idx = 0;
	if (dst > src)
	{
		while (idx < len)
		{
			((unsigned char *)dst)[len - 1 - idx]
				= ((unsigned char *)src)[len - 1 - idx];
			idx++;
		}
	}
	else
	{
		while (idx < len)
		{
			((unsigned char *)dst)[idx] = ((unsigned char *)src)[idx];
			idx++;
		}
	}
	return (dst);
}
