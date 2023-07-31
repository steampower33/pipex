/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:04:11 by seunlee2          #+#    #+#             */
/*   Updated: 2023/07/31 20:48:08 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_check_path(t_pipex *data, char *cmd)
{
	int		i;
	char	*path;

	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	i = 0;
	while (data->env_path[i])
	{
		path = ft_slushjoin(data->env_path[i], cmd);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (ft_strdup(cmd));
}

int	ft_len(char **argv)
{
	int	idx;

	idx = 0;
	while (argv[idx])
		idx++;
	return (idx);
}

int	ft_strchr_idx(char *s, char c)
{
	size_t	idx;
	size_t	len;

	idx = 0;
	len = ft_strlen(s);
	while (idx < len + 1)
	{
		if (s[idx] == (char)c)
			return (idx);
		idx++;
	}
	return (0);
}

void	ft_all_free(char **str)
{
	int	idx;

	if (!str)
		return ;
	idx = 0;
	while (str[idx])
	{
		free(str[idx]);
		idx++;
	}
	free(str);
}

char	*ft_strndup(const char *src, size_t size)
{
	size_t	dest_len;
	char	*dest;

	dest = (char *)malloc((sizeof(char) * (size + 1)));
	if (dest == NULL)
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
