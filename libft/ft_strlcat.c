/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:51:24 by seunlee2          #+#    #+#             */
/*   Updated: 2023/03/24 18:42:29 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	dest_idx;
	size_t	src_idx;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	dest_idx = dest_len;
	src_idx = 0;
	if (dest_len < dstsize)
	{
		while (src[src_idx] && (dest_idx + 1) < dstsize)
		{
			dst[dest_idx] = src[src_idx];
			dest_idx++;
			src_idx++;
		}
		dst[dest_idx] = '\0';
	}
	else
		dest_len = dstsize;
	return (dest_len + src_len);
}
