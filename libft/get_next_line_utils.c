/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:32:05 by seunlee2          #+#    #+#             */
/*   Updated: 2023/04/19 16:15:52 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_strchr_idx(const char *s, int c)
{
	size_t	idx;
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	idx = 0;
	while (idx < len + 1)
	{
		if (s[idx] == (char)c)
			return (idx);
		idx++;
	}
	return (0);
}

char	*ft_strcat(char *s, const char *s1, const char *s2, size_t s1_len)
{
	size_t	idx;

	idx = 0;
	while (s1[idx])
	{
		s[idx] = s1[idx];
		idx++;
	}
	idx = 0;
	while (s2[idx])
	{
		s[s1_len + idx] = s2[idx];
		idx++;
	}
	s[s1_len + idx] = '\0';
	return (s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	s1_len;
	size_t	s2_len;
	char	*s;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!s1 && !s2)
		return (ft_strndup("", 0));
	else if (!s1 || s1_len <= 0)
		return (ft_strndup(s2, s2_len));
	else if (!s2 || s2_len <= 0)
		return (ft_strndup(s1, s1_len));
	len = s1_len + s2_len + 1;
	s = (char *) malloc(sizeof(char) * len);
	if (!s)
		return (NULL);
	return (ft_strcat(s, s1, s2, s1_len));
}

char	*ft_strndup(const char *src, size_t size)
{
	size_t	dest_len;
	char	*dest;

	dest = (char *)malloc((sizeof(char) * (size + 1)));
	if (!dest)
		return (NULL);
	dest_len = 0;
	while (dest_len < size)
	{
		dest[dest_len] = src[dest_len];
		dest_len++;
	}
	dest[dest_len] = '\0';
	return (dest);
}
