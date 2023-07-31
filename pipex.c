/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:51:56 by seunlee2          #+#    #+#             */
/*   Updated: 2023/07/31 21:20:47 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_fork(t_pipex *data, char **envp, int idx)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_error_handler("fork error");
	else if (pid == 0)
	{
		close(data->fd[0]);
		dup2(data->fd[1], 1);
		close(data->fd[1]);
		if (execve(data->cmd_file[idx], data->cmd[idx], envp) == -1)
			ft_error_handler("command not found");
	}
	else
	{
		close(data->fd[1]);
		dup2(data->fd[0], 0);
		close(data->fd[0]);
		waitpid(pid, NULL, WNOHANG);
	}
}

void	ft_exec(t_pipex *data, char **argv, char **envp)
{
	int	idx;

	data->infile_fd = open(argv[1],
			O_RDONLY | O_CREAT, 0644);
	dup2(data->infile_fd, 0);
	close(data->infile_fd);
	pipe(data->fd);
	idx = 0;
	while (idx < data->cmd_cnt - 1)
		ft_fork(data, envp, idx++);
	data->outfile_fd = open(argv[ft_len(argv) - 1],
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->outfile_fd == -1)
		ft_error_handler("Outfile Error");
	dup2(data->outfile_fd, 1);
	close(data->outfile_fd);
	if (execve(data->cmd_file[idx], data->cmd[idx], envp) == -1)
		ft_error_handler("command not found");
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*data;

	data = (t_pipex *)malloc(sizeof(t_pipex));
	data->env_path = ft_env_chk(envp);
	if (!data->env_path)
		ft_error_handler("envp does not exist");
	ft_cnt_cmd(argc, argv, data);
	data->cmd_cnt = 2;
	data->pid_child = (int *)malloc(sizeof(int) * data->cmd_cnt);
	if (argc != 5)
		ft_error_handler("Not 4 Arguments");
	if (!ft_make_cmds(data))
		ft_error_handler("Malloc Error");
	ft_cmd_file(argc, data, argv);
	ft_cmd(argc, argv, data);
	ft_exec(data, argv, envp);
	ft_last_free(data);
	return (0);
}
