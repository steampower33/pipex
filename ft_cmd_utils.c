/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:52:26 by seunlee2          #+#    #+#             */
/*   Updated: 2023/07/31 21:20:23 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_cnt_cmd(int argc, char **argv, t_pipex *data)
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
			file = ft_check_path(data, str[0]);
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

void	ft_cmd_file(int argc, t_pipex *data, char **argv)
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
			file = ft_check_path(data, str[0]);
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

int	ft_make_cmds(t_pipex *data)
{
	data->cmd_file = (char **)malloc(sizeof(char *) * (data->cmd_cnt + 1));
	if (!data->cmd_file)
		ft_error_handler("Malloc Error");
	data->cmd_file[data->cmd_cnt] = NULL;
	data->cmd = (char ***)malloc(sizeof(char **) * (data->cmd_cnt + 1));
	if (!data->cmd)
		ft_error_handler("Malloc Error");
	data->cmd[data->cmd_cnt] = NULL;
	return (1);
}
