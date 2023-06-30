/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:06:09 by seunlee2          #+#    #+#             */
/*   Updated: 2023/06/30 18:19:44 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	child1(t_pipex data)
{
}

void	child2(t_pipex data)
{
}

int	make_pipe(t_pipex data, int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (pipe(fd) == -1)
		exit(1);
	pid1 = fork();
	if (pid1 == -1)
		exit(1);
	else if (pid1 == 0)
		child1(data);
	else
	{
		pid2 = fork();
		if (pid2 == -1)
			exit(1);
		else if (pid2 == 0)
			child2(data);
		else
		{
			close(fd[0]);
			close(fd[1]);
			waitpid(pid1, NULL, 0);
			waitpid(pid2, NULL, 0);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	if (argc != 5)
		exit(1);
	data.infile = argv[1];
	data.cmd1 = ft_split(argv[2], ' ');
	data.cmd2 = ft_split(argv[3], ' ');
	data.outfile = argv[4];
	make_pipe(data, argc, argv, envp);
}
