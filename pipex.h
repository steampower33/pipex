/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:06:00 by seunlee2          #+#    #+#             */
/*   Updated: 2023/07/24 21:43:54 by seunlee2         ###   ########.fr       */
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
}	t_pipex;

char	*ft_check_path(t_pipex *data, char *cmd, char **envp);
int		ft_len(char **argv);
int		ft_strchr_idx(char *s, char c);
void	ft_all_free(char **str);
char	*ft_strndup(const char *src, size_t size);

void	ft_child1(t_pipex *data, char **argv, char **envp, int *fd);
void	ft_child2(t_pipex *data, char **argv, char **envp, int *fd);
void	ft_make_pipe(t_pipex *data, char **argv, char **envp, int *fd);

void	ft_cnt_cmd(int argc, char **argv, char **envp, t_pipex *data);
void	ft_cmd_file(int argc, t_pipex *data, char **argv, char **envp);
char	*ft_get_file(char *argv, char **envp, t_pipex *data, int *flag);
void	ft_cmd1(int argc, char **argv, char **envp, t_pipex *data);
void	ft_cmd2(t_pipex *data);

char	*ft_newjoin(char const *s1, char const *s2);

char	*ft_slushjoin(char const *s1, char const *s2);

char	*ft_quote(char *str, int len);

#endif