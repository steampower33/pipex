/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:04:32 by seunlee2          #+#    #+#             */
/*   Updated: 2023/03/27 17:12:35 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	idx;
	size_t	len;

	idx = 0;
	len = ft_strlen(s);
	while (idx < len + 1)
	{
		if (s[idx] == (char)c)
			return ((char *)&s[idx]);
		idx++;
	}
	return (0);
}
