/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:06:09 by seunlee2          #+#    #+#             */
/*   Updated: 2023/07/03 22:00:19 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	child1(t_pipex *data, char **argv, char **envp, int *fd)
{
	char	*path;

	data->infile_fd = open(argv[1], O_RDONLY | O_CREAT, 0644);
	if (data->infile_fd == -1)
		exit(1);
	close(fd[0]);

	if (access(data->cmd1[0], X_OK) == 0)
		path = data->cmd1[0];
	else
	{
		int idx = 0;
		while (envp[idx])
		{
			if (ft_strnstr(envp[idx], "PATH=", 5))
			{
				// printf("%s\n", envp[idx]);
				data->env_path = ft_split(envp[idx] + 5, ':');
				int i = 0;
				while (data->env_path[i])
				{
					path = ft_slushjoin(data->env_path[i], data->cmd1[0]);
					// printf("%s\n", path);
					if (access(path, X_OK) == 0)
					{
						printf("O\n");
						break ;
					}
					i++;
				}
			}
			idx++;
		}
	}
	if (dup2(data->infile_fd, 0) == -1)
		exit(1);
	close(data->infile_fd);
	if (dup2(fd[1], 1) == -1)
		exit(1);
	close(fd[1]);
	execve(path, data->cmd1, envp);
}

void	child2(void)
{
}

void	make_pipe(t_pipex *data, char **argv, char **envp)
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
		child1(data, argv, envp, fd);
	else
	{
		pid2 = fork();
		if (pid2 == -1)
			exit(1);
		else if (pid2 == 0)
			child2();
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
	t_pipex	*data;

	if (argc != 5)
		exit(1);
	data = (t_pipex *)malloc(sizeof(t_pipex));
	data->cmd1 = ft_split(argv[2], ' ');
	data->cmd2 = ft_split(argv[3], ' ');
	make_pipe(data, argv, envp);
	free(data);
}
