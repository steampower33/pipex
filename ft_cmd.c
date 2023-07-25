/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:44:47 by seunlee2          #+#    #+#             */
/*   Updated: 2023/07/25 16:44:52 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_cmd1(int argc, char **argv, char **envp, t_pipex *data)
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
		file = ft_get_file(argv[idx], envp, data, &flag);
		if (flag == 0 || flag == 1)
			data->cmd1[++cnt] = ft_strdup(argv[idx]);
		else if (flag == 2)
		{
			tmp = data->cmd1[cnt];
			data->cmd1[cnt] = ft_newjoin(tmp, argv[idx]);
			free(tmp);
		}
		free(file);
		idx++;
	}
	ft_cmd2(data);
}

void	ft_cmd2(t_pipex *data)
{
	int		idx;
	int		space_idx;

	data->cmd2 = (char ***)malloc(sizeof(char **) * (data->cmd_cnt + 1));
	data->cmd2[data->cmd_cnt] = NULL;
	idx = 0;
	while (idx < data->cmd_cnt)
	{
		if (ft_strnstr(data->cmd1[idx], "awk", 3))
		{
			space_idx = ft_strchr_idx(data->cmd1[idx], ' ');
			data->cmd2[idx] = (char **)malloc(sizeof(char *) * 3);
			data->cmd2[idx][0] = ft_strndup(data->cmd1[idx], space_idx);
			data->cmd2[idx][1] = ft_quote(data->cmd1[idx] + space_idx + 1,
					ft_strlen(data->cmd1[idx] + space_idx + 1));
			data->cmd2[idx][2] = NULL;
		}
		else
			data->cmd2[idx] = ft_split(data->cmd1[idx], ' ');
		idx++;
	}
}
