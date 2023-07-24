/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:44:47 by seunlee2          #+#    #+#             */
/*   Updated: 2023/07/24 22:27:17 by seunlee2         ###   ########.fr       */
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
	while (idx < argc - 1)
	{
		if (ft_strchr(argv[idx], ' '))
		{
			str = ft_split(argv[idx], ' ');
			file = ft_check_path(data, str[0], envp);
			if (str)
				ft_all_free(str);
		}
		else
			file = ft_check_path(data, argv[idx], envp);
		if (file)
			cnt++;
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
	str = NULL;
	while (idx < argc - 1)
	{
		if (ft_strchr(argv[idx], ' '))
		{
			str = ft_split(argv[idx], ' ');
			file = ft_check_path(data, str[0], envp);
			if (str)
				ft_all_free(str);
		}
		else
			file = ft_check_path(data, argv[idx], envp);
		if (file)
			data->cmd_file[cnt++] = ft_strdup(file);
		free(file);
		idx++;
	}
}

char	*ft_get_file(char *argv, char **envp, t_pipex *data, int *flag)
{
	char	**str;
	char	*file;

	str = NULL;
	if (ft_strchr(argv, ' '))
	{
		str = ft_split(argv, ' ');
		file = ft_check_path(data, str[0], envp);
	}
	else
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

char	*ft_quote(char *str, int len)
{
	int	start;
	int	end;

	start = 0;
	end = 0;
	while (str[start])
	{
		if (str[start] == '`' || str[start] == '\'' || str[start] == '\"')
			start++;
		else
			break ;
	}
	while (str[len - 1 - end])
	{
		if (str[len - 1 - end] == '`' || str[len - 1 - end] == '\''
			|| str[len - 1 - end] == '\"')
			end++;
		else
			break ;
	}
	if (end != 0)
		end++;
	return (ft_strndup(str + start, len - end));
}
