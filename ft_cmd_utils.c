/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:52:26 by seunlee2          #+#    #+#             */
/*   Updated: 2023/07/28 18:13:42 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_cnt_cmd(int argc, char **argv, char **envp, t_pipex *data)
{
	int		idx;
	int		cnt;
	char	**str;
	char	*file;

	idx = 2;
	cnt = 0;
	file = NULL;
	while (idx < argc - 1)
	{
		str = ft_split(argv[idx], ' ');
		if (str[0])
			file = ft_check_path(data, str[0], envp);
		if (str)
			ft_all_free(str);
		if (file)
		{
			cnt++;
			free(file);
			file = NULL;
		}
		idx++;
	}
	data->cmd_cnt = cnt;
}

void	ft_cmd_file(int argc, t_pipex *data, char **argv, char **envp)
{
	int		idx;
	char	**str;
	char	*file;
	int		cnt;

	idx = 2;
	cnt = 0;
	str = NULL;
	file = NULL;
	while (idx < argc - 1)
	{
		str = ft_split(argv[idx], ' ');
		if (str[0])
			file = ft_check_path(data, str[0], envp);
		if (str)
			ft_all_free(str);
		if (file)
		{
			data->cmd_file[cnt++] = ft_strdup(file);
			free(file);
			file = NULL;
		}
		idx++;
	}
}

char	*ft_get_file(char *argv, char **envp, t_pipex *data, int *flag)
{
	char	**str;
	char	*file;

	str = NULL;
	file = NULL;
	if (ft_strchr(argv, ' '))
	{
		str = ft_split(argv, ' ');
		file = ft_check_path(data, str[0], envp);
	}
	else if (argv[0])
		file = ft_check_path(data, argv, envp);
	if (str && file)
		*flag = 0;
	else if (!str && file)
		*flag = 1;
	else if (!str && !file)
		*flag = 2;
	if (str)
		free(str);
	return (file);
}

int	ft_make_cmds(t_pipex *data)
{
	data->cmd_file = (char **)malloc(sizeof(char *) * (data->cmd_cnt + 1));
	if (!data->cmd_file)
		return (0);
	data->cmd_file[data->cmd_cnt] = NULL;
	data->cmd1 = (char **)malloc(sizeof(char *) * (data->cmd_cnt + 1));
	if (!data->cmd1)
		return (0);
	data->cmd1[data->cmd_cnt] = NULL;
	data->cmd2 = (char ***)malloc(sizeof(char **) * (data->cmd_cnt + 1));
	if (!data->cmd2)
		return (0);
	data->cmd2[data->cmd_cnt] = NULL;
	return (1);
}
