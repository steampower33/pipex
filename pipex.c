/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:06:09 by seunlee2          #+#    #+#             */
/*   Updated: 2023/07/24 19:28:55 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1(t_pipex *data, char **argv, char **envp, int *fd)
{
	data->infile_fd = open(argv[1], O_RDONLY | O_CREAT, 0644);
	if (data->infile_fd == -1)
		exit(1);
	close(fd[0]);
	if (dup2(data->infile_fd, 0) == -1)
		exit(1);
	close(data->infile_fd);
	if (dup2(fd[1], 1) == -1)
		exit(1);
	close(fd[1]);
	if (execve(data->cmd_file[0], data->cmd_option2[0], envp) == -1)
		exit(1);
}

void	child2(t_pipex *data, char **argv, char **envp, int *fd)
{
	data->outfile_fd = open(argv[ft_len(argv) - 1], O_WRONLY | O_CREAT, 0644);
	if (data->outfile_fd == -1)
		exit(1);
	close(fd[1]);
	if (dup2(fd[0], 0) == -1)
		exit(1);
	close(fd[0]);
	if (dup2(data->outfile_fd, 1) == -1)
		exit(1);
	close(data->outfile_fd);
	if (execve(data->cmd_file[1], data->cmd_option2[1], envp) == -1)
		exit(1);
}

void	make_pipe(t_pipex *data, char **argv, char **envp, int *fd)
{
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
			child2(data, argv, envp, fd);
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
	int		fd[2];
	int		idx;

	data = (t_pipex *)malloc(sizeof(t_pipex));
	cnt_cmd(argc, argv, envp, data);
	if (data->cmd_cnt != 2)
		exit(1);
	data->cmd_file = (char **)malloc(sizeof(char *) * (data->cmd_cnt + 1));
	data->cmd_file[data->cmd_cnt] = NULL;
	data->cmd_option = (char **)malloc(sizeof(char *) * (data->cmd_cnt + 1));
	data->cmd_option[data->cmd_cnt] = NULL;
	ft_cmd_file(argc, data, argv, envp);
	cmd_option(argc, argv, envp, data);
	make_pipe(data, argv, envp, fd);
	all_free(data->cmd_file);
	all_free(data->cmd_option);
	idx = 0;
	while (data->cmd_option2[idx])
		all_free(data->cmd_option2[idx++]);
	free(data->cmd_option2);
}
