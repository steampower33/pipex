/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:44:47 by seunlee2          #+#    #+#             */
/*   Updated: 2023/07/22 20:22:46 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	cnt_cmd(int argc, char **argv, char **envp, t_pipex *data)
{
	int		idx;
	int		cnt;
	char	**str;
	char	*file;

	idx = 2;
	cnt = 0;
	while (idx < argc - 1)
	{
		if (ft_strchr(argv[idx], ' '))
		{
			str = ft_split(argv[idx], ' ');
			file = check_path(data, str[0], envp);
		}
		else
			file = check_path(data, argv[idx], envp);
		if (file)
			cnt++;
		if (str)
			all_free(str);
		free(file);
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
	while (idx < argc - 1)
	{
		if (ft_strchr(argv[idx], ' '))
		{
			str = ft_split(argv[idx], ' ');
			file = check_path(data, str[0], envp);
		}
		else
			file = check_path(data, argv[idx], envp);
		if (file)
			data->cmd_file[cnt++] = ft_strdup(file);
		if (str)
			all_free(str);
		free(file);
		idx++;
	}
}

char	*get_file(char *argv, char **envp, t_pipex *data, int *flag)
{
	char	**str;
	char	*file;

	str = NULL;
	if (ft_strchr(argv, ' '))
	{
		str = ft_split(argv, ' ');
		file = check_path(data, str[0], envp);
	}
	else
		file = check_path(data, argv, envp);
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

void	cmd_option2(t_pipex *data)
{
	int		idx;
	int		idx2;
	char	**tmp;

	data->cmd_option2 = (char ***)malloc(sizeof(char **) * (data->cmd_cnt + 1));
	data->cmd_option2[data->cmd_cnt] = NULL;
	idx = 0;
	while (idx < data->cmd_cnt)
	{
		data->cmd_option2[idx] = ft_split(data->cmd_option[idx], ' ');
		idx2 = 0;
		while (data->cmd_option2[idx][idx2])
		{
			if (ft_strchr(data->cmd_option2[idx][idx2], '\''))
				ft_split(data->cmd_option2[idx][idx2], '\'');
			if (ft_strchr(data->cmd_option2[idx][idx2], '\"'))
				ft_split(data->cmd_option2[idx][idx2], '\"');
			if (ft_strchr(data->cmd_option2[idx][idx2], '`'))
				ft_split(data->cmd_option2[idx][idx2], '`');
			idx2++;
		}
		idx++;
	}
}

void	cmd_option(int argc, char **argv, char **envp, t_pipex *data)
{
	int		idx;
	char	*file;
	int		cnt;
	int		flag;
	char	*tmp;

	idx = 2;
	cnt = -1;
	while (idx < argc - 1)
	{
		file = get_file(argv[idx], envp, data, &flag);
		if (flag == 0 || flag == 1)
			data->cmd_option[++cnt] = ft_strdup(argv[idx]);
		else if (flag == 2)
		{
			tmp = data->cmd_option[cnt];
			data->cmd_option[cnt] = ft_newjoin(tmp, argv[idx]);
			free(tmp);
		}
		free(file);
		idx++;
	}
	cmd_option2(data);
}
