/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:06:00 by seunlee2          #+#    #+#             */
/*   Updated: 2023/06/29 19:21:12 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include "libft.h"

typedef struct s_pipex
{
	char	*infile;
	char	**cmd1;
	char	**cmd2;
	char	*outfile;
}	t_pipex;

#endif