/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:56:50 by seunlee2          #+#    #+#             */
/*   Updated: 2023/07/31 21:00:15 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_last_free(t_pipex *data)
{
	int	idx;

	if (!data->cmd || data->cmd_file)
		return ;
	ft_all_free(data->cmd_file);
	idx = 0;
	while (data->cmd[idx])
		ft_all_free(data->cmd[idx++]);
	free(data->cmd);
}

void	ft_error_handler(char *str)
{
	perror(str);
	exit(1);
}

char	**ft_env_chk(char **envp)
{
	int		i;
	char	**tmp;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
		{
			tmp = ft_split(envp[i] + 5, ':');
			return (tmp);
		}
		i++;
	}
	return (NULL);
}
