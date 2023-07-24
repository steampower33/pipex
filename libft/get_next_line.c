/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:05:31 by seunlee2          #+#    #+#             */
/*   Updated: 2023/06/29 19:47:07 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readline(int fd, char *buf)
{
	char	readline[BUFFER_SIZE + 1];
	char	*res;
	char	*tmp;
	int		size;

	size = 1;
	res = buf;
	while (size)
	{
		size = read(fd, readline, BUFFER_SIZE);
		if (size == -1)
		{
			free(buf);
			return (NULL);
		}
		readline[size] = '\0';
		tmp = res;
		res = ft_strjoin(res, readline);
		free(tmp);
		if (!res)
			return (NULL);
		if (ft_strchr_idx(res, 10))
			break ;
	}
	return (res);
}

char	*ft_set_buf(char **buf)
{
	char	*res;
	char	*tmp;
	int		idx;

	idx = 0;
	while ((*buf)[idx] && (*buf)[idx++] != '\n')
		;
	res = ft_strndup(*buf, idx);
	if (!res)
		return (NULL);
	tmp = *buf;
	*buf = ft_strndup(*buf + idx, ft_strlen(*buf) - idx);
	free(tmp);
	return (res);
}

t_list	*ft_find_fd_node(t_list **fd_list, int fd)
{
	t_list	*fd_node;
	t_list	*fd_prev;

	fd_prev = NULL;
	fd_node = *fd_list;
	while (fd_node)
	{
		if (fd_node->fd == fd)
			return (fd_node);
		fd_prev = fd_node;
		fd_node = fd_node->next;
	}
	fd_node = (t_list *)malloc(sizeof(t_list));
	if (!fd_node)
		return (NULL);
	fd_node->fd = fd;
	fd_node->buf = NULL;
	fd_node->next = NULL;
	if (fd_prev)
		fd_prev->next = fd_node;
	else
		*fd_list = fd_node;
	return (fd_node);
}

void	ft_del_fd_node(t_list **fd_list, int fd)
{
	t_list	*fd_prev;
	t_list	*fd_node;

	fd_prev = NULL;
	fd_node = *fd_list;
	while (fd_node)
	{
		if (fd_node->fd == fd)
			break ;
		fd_prev = fd_node;
		fd_node = fd_node->next;
	}
	if (fd_prev)
		fd_prev->next = fd_node->next;
	else
		*fd_list = fd_node->next;
	free(fd_node->buf);
	free(fd_node);
}

char	*get_next_line(int fd)
{
	static t_list	*fd_list;
	t_list			*fd_node;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fd_node = ft_find_fd_node(&fd_list, fd);
	if (!fd_node)
		return (NULL);
	fd_node->buf = ft_readline(fd, fd_node->buf);
	if (!fd_node->buf || !*fd_node->buf)
	{
		ft_del_fd_node(&fd_list, fd);
		return (NULL);
	}
	line = ft_set_buf(&fd_node->buf);
	if (!line)
		ft_del_fd_node(&fd_list, fd);
	return (line);
}
