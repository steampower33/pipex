/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:52:55 by seunlee2          #+#    #+#             */
/*   Updated: 2023/03/23 15:09:13 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			idx;

	idx = 0;
	while (idx < n)
	{
		if (((unsigned char *)s)[idx] == (unsigned char)c)
			return ((unsigned char *)&s[idx]);
		idx++;
	}
	return (NULL);
}
