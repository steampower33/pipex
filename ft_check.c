/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:04:11 by seunlee2          #+#    #+#             */
/*   Updated: 2023/07/17 20:25:02 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

char	*check_path(t_pipex *data, char *cmd, char **envp)
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
