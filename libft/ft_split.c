/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:55:16 by seunlee2          #+#    #+#             */
/*   Updated: 2023/06/29 19:12:40 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_res_len(const char *s, char c, size_t start, size_t end)
{
	size_t	cnt;

	cnt = 0;
	while (s[end])
	{
		if (s[end] == c)
		{
			if (!(start == 0 && end == 0) && s[end - 1] != c)
				cnt++;
			start = end + 1;
		}
		else if (s[end + 1] == '\0')
			cnt++;
		end++;
	}
	return (cnt + 1);
}

static char	*ft_strndup(const char *src, size_t size, size_t *is_null)
{
	size_t	dest_len;
	char	*dest;

	dest = (char *)malloc((sizeof(char) * (size + 1)));
	if (dest == NULL)
	{
		*is_null = 1;
		return (NULL);
	}
	dest_len = 0;
	while (dest_len < size)
	{
		dest[dest_len] = src[dest_len];
		dest_len++;
	}
	dest[dest_len] = '\0';
	return (dest);
}

static void	ft_all_free(char	**result)
{
	size_t	idx;

	idx = 0;
	while (result[idx])
	{
		free(result[idx]);
		idx++;
	}
	free(result);
}

static size_t	ft_do_split(char **result, char const *s, char c)
{
	size_t	start;
	size_t	end;
	size_t	row;
	size_t	is_null;

	start = 0;
	end = 0;
	row = 0;
	is_null = 0;
	while (end < ft_strlen(s))
	{
		if (s[end] == c)
		{
			if (!(start == 0 && end == 0) && s[end - 1] != c)
				result[row++] = ft_strndup(&s[start], end - start, &is_null);
			start = end + 1;
		}
		else if (s[end + 1] == '\0')
			result[row++] = ft_strndup(&s[start], end - start + 1, &is_null);
		if (is_null)
			return (0);
		end++;
	}
	result[row] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	result = (char **)malloc(sizeof(char *) * (ft_res_len(s, c, 0, 0)));
	if (!result)
		return (NULL);
	if (!ft_do_split(result, s, c))
	{
		ft_all_free(result);
		return (NULL);
	}
	return (result);
}
