/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:40:02 by seunlee2          #+#    #+#             */
/*   Updated: 2023/03/27 17:11:09 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat(char *s, const char *s1, const char *s2)
{
	size_t	idx;

	idx = 0;
	while (idx < ft_strlen(s1))
	{
		s[idx] = s1[idx];
		idx++;
	}
	idx = 0;
	while (idx < ft_strlen(s2))
	{
		s[ft_strlen(s1) + idx] = s2[idx];
		idx++;
	}
	s[ft_strlen(s1) + idx] = '\0';
	return (s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*s;

	if (!ft_strlen(s1) && !ft_strlen(s2))
		return ((char *)ft_calloc(sizeof(char), 1));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	s = (char *) malloc(sizeof(char) * len);
	if (!s)
		return (NULL);
	return (ft_strcat(s, s1, s2));
}
