/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:46:49 by seunlee2          #+#    #+#             */
/*   Updated: 2023/03/23 15:04:03 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	idx;
	size_t	len;
	char	*result_c;

	idx = 0;
	len = ft_strlen(s);
	result_c = 0;
	while (idx < len + 1)
	{
		if (s[idx] == (char)c)
			result_c = ((char *)&s[idx]);
		idx++;
	}
	return (result_c);
}
