/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:04:11 by seunlee2          #+#    #+#             */
/*   Updated: 2023/07/25 16:44:45 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_check_path(t_pipex *data, char *cmd, char **envp)
{
	int		i;
	int		j;
	char	*path;

	if (access(cmd, X_OK) == 0)
		return (cmd);
	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
		{
			data->env_path = ft_split(envp[i] + 5, ':');
			j = 0;
			while (data->env_path[j])
			{
				path = ft_slushjoin(data->env_path[j], cmd);
				if (access(path, X_OK) == 0)
					return (path);
				free(path);
				j++;
			}
		}
		i++;
	}
	return (NULL);
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

	if (!str || !*str)
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
