/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:30:02 by seunlee2          #+#    #+#             */
/*   Updated: 2023/03/24 16:12:51 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	str_len;
	size_t	find_len;
	size_t	idx;

	str_len = ft_strlen(haystack);
	find_len = ft_strlen(needle);
	if (str_len < find_len)
		return (NULL);
	idx = 0;
	while (idx < len)
	{
		if ((haystack[idx] == needle[0]
				&& !ft_strncmp(&haystack[idx], needle, find_len)
				&& (idx + find_len - 1 < len)) || needle[0] == '\0')
			return (&((char *)haystack)[idx]);
		idx++;
	}
	if (*needle == '\0')
		return (&((char *)haystack)[idx]);
	else
		return (NULL);
}
