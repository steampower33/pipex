/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:51:56 by seunlee2          #+#    #+#             */
/*   Updated: 2023/07/28 19:58:40 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child1(t_pipex *data, char **argv, char **envp)
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

void	ft_child2(t_pipex *data, char **argv, char **envp)
{
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
	if (execve(data->cmd_file[1], data->cmd2[1], envp) == -1)
		ft_error_handler("Execve Error");
}

void	ft_send_data(t_pipex *data, char **argv, char **envp)
{
	char	**c;

	c = (char **)malloc(sizeof(char *) * 2);
	c[0] = ft_strdup("cat");
	c[1] = NULL;
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
	if (execve("/bin/cat", c, envp) == -1)
		ft_error_handler("Execve Error");
	ft_all_free(c);
}

void	ft_get_data(t_pipex *data, char **argv, char **envp)
{
	char	**c;

	c = (char **)malloc(sizeof(char *) * 2);
	c[0] = ft_strdup("cat");
	c[1] = NULL;
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
	if (execve("/bin/cat", c, envp) == -1)
		ft_error_handler("Execve Error");
	ft_all_free(c);
}

void	ft_child(t_pipex *data, char **argv, char **envp, int depth)
{
	printf("depth => %d\n", depth);
	if (depth == 0)
		ft_send_data(data, argv, envp);
	else if (depth == 1)
		ft_get_data(data, argv, envp);
}

void	ft_fork_rec(t_pipex *data, char **argv, char **envp, int depth)
{
	int	pid;
	int	wait;
	int	idx;

	pid = fork();
	if (pid == -1)
		ft_error_handler("Fork Error");
	else if (pid == 0)
		ft_child(data, argv, envp, depth);
	else
	{
		data->pid_child[depth] = pid;
		if (data->cmd_cnt == depth + 1)
		{
			idx = 0;
			if (depth > 0)
			{
				printf("data->pid_child[%d] => %d\n", depth, data->pid_child[depth]);
				wait = waitpid(data->pid_child[depth - 1], NULL, 0);
			}
		}
		else
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
