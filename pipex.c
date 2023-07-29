/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:51:56 by seunlee2          #+#    #+#             */
/*   Updated: 2023/07/29 19:30:45 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_send_data(t_pipex *data, char **argv, char **envp)
{
	data->infile_fd = open(argv[1], O_RDONLY, 0644);
	if (data->infile_fd == -1)
		ft_error_handler("File Open Error");
	close(data->fd[0]);
	if (dup2(data->infile_fd, 0) == -1)
		ft_error_handler("Dup2 Error");
	close(data->infile_fd);
	if (dup2(data->fd[1], 1) == -1)
		ft_error_handler("Dup2 Error");
	close(data->fd[1]);
	if (execve(data->cmd_file[0], data->cmd2[0], envp) == -1)
		ft_error_handler("Execve Error");
}

void	ft_get_data(t_pipex *data, char **argv, char **envp)
{
	int	idx;

	idx = data->cmd_cnt - 1;
	data->outfile_fd = open(argv[ft_len(argv) - 1], O_WRONLY | O_CREAT, 0644);
	if (data->outfile_fd == -1)
		ft_error_handler("File Open Error");
	close(data->fd[1]);
	if (dup2(data->fd[0], 0) == -1)
		ft_error_handler("Dup2 Error");
	close(data->fd[0]);
	if (dup2(data->outfile_fd, 1) == -1)
		ft_error_handler("Dup2 Error");
	close(data->outfile_fd);
	if (execve(data->cmd_file[idx], data->cmd2[idx], envp) == -1)
		ft_error_handler("Execve Error");
}

void	ft_inpipe(t_pipex *data, char **envp, int depth)
{
	if (dup2(data->fd[0], 0) == -1)
		ft_error_handler("Dup2 Error");
	close(data->fd[0]);
	if (dup2(data->fd[1], 1) == -1)
		ft_error_handler("Dup2 Error");
	close(data->fd[1]);
	if (execve(data->cmd_file[depth], data->cmd2[depth], envp) == -1)
		ft_error_handler("Execve Error");
}

void	ft_child(t_pipex *data, char **argv, char **envp, int depth)
{
	printf("cmd_cnt => %d, depth => %d\n", data->cmd_cnt, depth);
	if (depth == 0)
		ft_send_data(data, argv, envp);
	else if (depth == data->cmd_cnt - 1)
		ft_get_data(data, argv, envp);
	else
		ft_inpipe(data, envp, depth);
}

void	ft_fork_rec(t_pipex *data, char **argv, char **envp, int depth)
{
	int	pid;
	int	wait;

	pid = fork();
	if (pid == -1)
		ft_error_handler("Fork Error");
	else if (pid == 0)
		ft_child(data, argv, envp, depth);
	else
	{
		data->pid_child[depth] = pid;
		if (depth > 0)
		{
			printf("depth => %d\n", depth);
			wait = waitpid(data->pid_child[depth - 1], NULL, 0);
			printf("wait => %d, pip_child[%d] => %d\n", wait, depth, data->pid_child[depth - 1]);
		}
		if (depth != data->cmd_cnt)
			ft_fork_rec(data, argv, envp, depth + 1);
	}
}

void	ft_make_pipe(t_pipex *data, char **argv, char **envp)
{
	if (pipe(data->fd) == -1)
		ft_error_handler("Make Pipe Error");
	ft_fork_rec(data, argv, envp, 0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*data;

	data = (t_pipex *)malloc(sizeof(t_pipex));
	ft_cnt_cmd(argc, argv, envp, data);
	data->pid_child = (int *)malloc(sizeof(int) * data->cmd_cnt);
	// if (argc != 5)
	// 	ft_error_handler("Not 4 Arguments");
	// if (data->cmd_cnt != 2)
	// 	ft_error_handler("Not 2 cmds");
	if (!ft_make_cmds(data))
		ft_error_handler("Malloc Error");
	ft_cmd_file(argc, data, argv, envp);
	ft_cmd1(argc, argv, envp, data);
	ft_make_pipe(data, argv, envp);
	ft_last_free(data);
	return (0);
}
