/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:19:17 by seunlee2          #+#    #+#             */
/*   Updated: 2023/03/27 17:11:30 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_is_set(char c, char const *set)
{
	size_t	idx;

	idx = 0;
	while (idx < ft_strlen(set))
	{
		if (set[idx] == c)
			return (1);
		idx++;
	}
	return (0);
}

static size_t	ft_get_start(char const *s1, char const *set)
{
	size_t	idx;

	idx = 0;
	while (idx < ft_strlen(s1))
	{
		if (!ft_is_set(s1[idx], set))
			return (idx);
		idx++;
	}
	return (idx);
}

static size_t	ft_get_end(char const *s1, char const *set)
{
	size_t	idx;

	if (ft_strlen(s1) == 0)
		idx = 0;
	else
		idx = ft_strlen(s1) - 1;
	while (idx > 0)
	{
		if (!ft_is_set(s1[idx], set))
			return (idx + 1);
		idx--;
	}
	return (idx);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	idx;
	size_t	start;
	size_t	end;
	char	*s;

	start = ft_get_start(s1, set);
	end = ft_get_end(s1, set);
	if (start >= ft_strlen(s1))
		return ((char *)ft_calloc(sizeof(char), 1));
	s = (char *) malloc(sizeof(char) * (end - start + 1));
	if (!s)
		return (NULL);
	idx = 0;
	while (start < end)
	{
		s[idx] = s1[start];
		idx++;
		start++;
	}
	s[idx] = '\0';
	return (s);
}
