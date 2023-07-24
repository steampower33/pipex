/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:06:40 by seunlee2          #+#    #+#             */
/*   Updated: 2023/04/19 16:18:02 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	struct s_list	*next;
	char			*buf;
	int				fd;
}	t_list;

char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);
int		ft_strchr_idx(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strcat(char *s, const char *s1, const char *s2, size_t s1_len);
char	*ft_strndup(const char *src, size_t size);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42

#endif