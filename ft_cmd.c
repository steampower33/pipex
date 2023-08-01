/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:52:34 by seunlee2          #+#    #+#             */
/*   Updated: 2023/08/01 16:45:52 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_cmd(int argc, char **argv, t_pipex *data)
{
	int		idx;

	idx = 2;
	while (idx < argc - 1)
	{
		if (ft_strnstr(argv[idx], "awk", 3))
		{
			data->cmd[idx - 2] = (char **)malloc(sizeof(char *) * 3);
			if (!data->cmd[idx - 2])
				ft_error_handler("malloc error", 1);
			data->cmd[idx - 2][0] = ft_strdup("awk");
			if (*(argv[idx] + 4) == '\'')
				data->cmd[idx - 2][1] = ft_strtrim(argv[idx] + 4, "\'");
			else if (*(argv[idx] + 4) == '\"')
				data->cmd[idx - 2][1] = ft_strtrim(argv[idx] + 4, "\"");
			data->cmd[idx - 2][2] = NULL;
		}
		else
			data->cmd[idx - 2] = ft_split(argv[idx], ' ');
		idx++;
	}
}
