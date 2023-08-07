/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:51:56 by seunlee2          #+#    #+#             */
/*   Updated: 2023/08/07 17:42:52 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_fork(t_pipex *data, char **envp, int idx, int flag)
{
	pid_t	pid;

	if (pipe(data->fd) == -1)
		ft_error_handler("pipe not found", 1);
	pid = fork();
	if (pid == -1)
		ft_error_handler("fork error", 1);
	else if (pid == 0)
	{
		close(data->fd[0]);
		dup2(data->fd[1], 1);
		if (flag == -1)
			ft_error_handler("infile open error", 1);
		if (execve(data->cmd_file[idx], data->cmd[idx], envp) == -1)
			ft_error_handler("command not found", 127);
	}
	else
	{
		close(data->fd[1]);
		dup2(data->fd[0], 0);
		waitpid(pid, NULL, WNOHANG);
	}
}

void	ft_exec(t_pipex *data, char **argv, char **envp)
{
	int	idx;

	data->infile_fd = open(argv[1], O_RDONLY);
	dup2(data->infile_fd, 0);
	close(data->infile_fd);
	idx = 0;
	ft_fork(data, envp, idx++, data->infile_fd);
	while (idx < data->cmd_cnt - 1)
		ft_fork(data, envp, idx++, 0);
	data->outfile_fd = open(argv[ft_len(argv) - 1],
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->outfile_fd == -1)
		ft_error_handler("outfile open error", 1);
	dup2(data->outfile_fd, 1);
	close(data->outfile_fd);
	if (execve(data->cmd_file[idx], data->cmd[idx], envp) == -1)
		ft_error_handler("command not found", 127);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*data;

	if (argc != 5)
		ft_error_handler("does not 5 auguments", 1);
	data = (t_pipex *)malloc(sizeof(t_pipex));
	data->env_path = ft_env_chk(envp);
	if (!data->env_path)
		ft_error_handler("envp does not exist", 1);
	data->cmd_cnt = argc - 3;
	if (!ft_make_cmds(data))
		ft_error_handler("malloc error", 1);
	ft_cmd_file(argc, data, argv);
	ft_cmd(argc, argv, data);
	ft_exec(data, argv, envp);
	ft_last_free(data);
	return (0);
}
