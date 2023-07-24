/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:53:23 by seunlee2          #+#    #+#             */
/*   Updated: 2023/03/27 17:11:50 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(
	char const *s, char	*sub_s, unsigned int start, size_t len)
{
	size_t	idx;

	idx = 0;
	while (s[start + idx] && idx < len)
	{
		sub_s[idx] = s[start + idx];
		idx++;
	}
	sub_s[idx] = '\0';
	return (sub_s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;

	if (start > ft_strlen(s))
		return ((char *)ft_calloc(sizeof(char), 1));
	if (start + len < ft_strlen(s))
		sub_s = (char *) malloc(sizeof(char) * (len + 1));
	else
		sub_s = (char *) malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	if (!sub_s)
		return (NULL);
	return (ft_strcpy(s, sub_s, start, len));
}
