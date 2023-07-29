/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:06:00 by seunlee2          #+#    #+#             */
/*   Updated: 2023/07/29 20:14:33 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_pipex
{
	int		infile_fd;
	int		outfile_fd;
	int		cmd_cnt;
	char	**env_path;
	char	**cmd_file;
	char	**cmd1;
	char	***cmd2;
	int		fd[2];
	int		*pid_child;
}	t_pipex;

char	*ft_check_path(t_pipex *data, char *cmd, char **envp);
int		ft_strchr_idx(char *s, char c);
void	ft_all_free(char **str);
void	ft_last_free(t_pipex *data);
char	*ft_strndup(const char *src, size_t size);
int		ft_len(char **argv);
void	ft_error_handler(char *str);
void	ft_exec(t_pipex *data, char **argv, char **envp);
int		ft_make_cmds(t_pipex *data);
void	ft_cnt_cmd(int argc, char **argv, char **envp, t_pipex *data);
void	ft_cmd_file(int argc, t_pipex *data, char **argv, char **envp);
char	*ft_get_file(char *argv, char **envp, t_pipex *data, int *flag);
void	ft_cmd1(int argc, char **argv, char **envp, t_pipex *data);
void	ft_cmd1_split(char *argv, char **envp, t_pipex *data);
void	ft_cmd2(t_pipex *data);
char	*ft_newjoin(char const *s1, char const *s2);
char	*ft_slushjoin(char const *s1, char const *s2);

#endif