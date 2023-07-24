/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:49:34 by seunlee2          #+#    #+#             */
/*   Updated: 2023/03/27 17:10:20 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_itoa_rec(char *res, long n)
{
	size_t	idx;

	if (n < 0)
	{
		n *= -1;
		res[0] = '-';
		ft_itoa_rec(res, n);
	}
	else if (n >= 0)
	{
		if (0 <= n && n <= 9)
		{
			idx = 0;
			while (res[idx])
				idx++;
			res[idx] = '0' + n;
		}
		else
		{
			ft_itoa_rec(res, n / 10);
			ft_itoa_rec(res, n % 10);
		}
	}
}

static size_t	ft_ilen(long n)
{
	int	cnt;

	cnt = 0;
	if (n < 0)
	{
		cnt++;
		n *= -1;
	}
	if (n == 0)
		return (2);
	while (n > 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt + 1);
}

char	*ft_itoa(int n)
{
	size_t	res_len;
	char	*res;

	res_len = ft_ilen(n);
	res = (char *)ft_calloc(sizeof(char), res_len);
	if (!res)
		return (NULL);
	ft_itoa_rec(res, n);
	return (res);
}
