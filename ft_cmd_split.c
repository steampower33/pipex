/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:44:47 by seunlee2          #+#    #+#             */
/*   Updated: 2023/07/22 19:47:13 by seunlee2         ###   ########.fr       */
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

void	cmd_option2(t_pipex *data)
{
	int	idx;
	int	space;

	data->cmd_option2 = (char ***)malloc(sizeof(char **) * (data->cmd_cnt + 1));
	data->cmd_option2[data->cmd_cnt] = NULL;
	idx = 0;
	while (idx < data->cmd_cnt)
	{
		data->cmd_option2[idx] = (char **)malloc(sizeof(char *) * 3);
		data->cmd_option2[idx][2] = NULL;
		space = ft_strchr_idx(data->cmd_option[0], ' ');
		data->cmd_option2[idx][0] = ft_strndup(data->cmd_option[0], space);
		data->cmd_option2[idx][1] = ft_strndup(data->cmd_option[0] + space,
				ft_strlen(data->cmd_option[0]) - space);
		int j = 0;
		while (data->cmd_option2[idx][j])
		{
			printf("%s\n", data->cmd_option2[idx][j]);
			j++;
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
