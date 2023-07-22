/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:06:00 by seunlee2          #+#    #+#             */
/*   Updated: 2023/07/22 19:44:19 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct s_pipex
{
	int		infile_fd;
	int		outfile_fd;
	int		cmd_cnt;
	char	**env_path;
	char	**cmd_file;
	char	**cmd_option;
	char	***cmd_option2;
}	t_pipex;

char	*check_path(t_pipex *data, char *cmd, char **envp);
int		ft_len(char **argv);

void	make_pipe(t_pipex *data, char **argv, char **envp, int *fd);
void	child1(t_pipex *data, char **argv, char **envp, int *fd);
void	child2(t_pipex *data, char **argv, char **envp, int *fd);
char	*ft_slushjoin(char const *s1, char const *s2);

void	ft_cmd_file(int argc, t_pipex *data, char **argv, char **envp);
void	cnt_cmd(int argc, char **argv, char **envp, t_pipex *data);
char	*get_file(char *argv, char **envp, t_pipex *data, int *flag);
void	cmd_option(int argc, char **argv, char **envp, t_pipex *data);

void	all_free(char **str);

char	*ft_newjoin(char const *s1, char const *s2);
char	*ft_strndup(const char *src, size_t size);

#endif