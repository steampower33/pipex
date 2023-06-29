/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:06:09 by seunlee2          #+#    #+#             */
/*   Updated: 2023/06/29 19:24:07 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int	make_pipe(int argc char **argv)
// {
// 	int	fd[2];
// 	int	pip1;
// 	int	pip2;

// 	if (pipe(fd) == -1)
// 		exit(1);
// }

int	main(int argc, char **argv)
{
	t_pipex	data;

	if (argc != 5)
		exit(1);
	data.infile = argv[1];
	
}
