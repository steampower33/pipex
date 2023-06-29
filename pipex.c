/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:06:09 by seunlee2          #+#    #+#             */
/*   Updated: 2023/06/29 17:55:11 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	printf("argc => %d\n", argc);
	while (*argv)
		printf("%s", *argv++);
	printf("\n");
	while (*envp)
		printf("%s\n", *envp++);
}
