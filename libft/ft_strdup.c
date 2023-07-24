/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:50:26 by seunlee2          #+#    #+#             */
/*   Updated: 2023/03/23 15:25:37 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	src_len;
	size_t	dest_len;
	char	*dest;

	src_len = 0;
	while (s1[src_len])
		src_len++;
	dest = (char *)malloc((sizeof(char) * (src_len + 1)));
	if (dest == NULL)
		return (NULL);
	dest_len = 0;
	while (dest_len < src_len)
	{
		dest[dest_len] = s1[dest_len];
		dest_len++;
	}
	dest[dest_len] = '\0';
	return (dest);
}
