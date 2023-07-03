/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:06:00 by seunlee2          #+#    #+#             */
/*   Updated: 2023/07/03 21:10:35 by seunlee2         ###   ########.fr       */
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
	char	**cmd1;
	char	**cmd2;
	int		outfile_fd;
	char	**env_path;
}	t_pipex;

char	*ft_slushjoin(char const *s1, char const *s2);

#endif