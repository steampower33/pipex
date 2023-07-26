/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:56:50 by seunlee2          #+#    #+#             */
/*   Updated: 2023/07/26 17:59:32 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_last_free(t_pipex *data)
{
	int	idx;

	ft_all_free(data->cmd_file);
	ft_all_free(data->cmd1);
	idx = 0;
	while (data->cmd2[idx])
		ft_all_free(data->cmd2[idx++]);
	free(data->cmd2);
}

void	ft_error_handler(char *str)
{
	perror(str);
	exit(1);
}
