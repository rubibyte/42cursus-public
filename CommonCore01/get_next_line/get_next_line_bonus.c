/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:09:25 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/29 18:07:00 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(char *str);
char	*ft_join(char *s1, char *s2);
char	*ft_fetch_line(char *general_buf);
char	*ft_cut_line(char *general_buf);

char	*ft_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (NULL);
}

char	*ft_read(int fd, char *general_buf)
{
	char	read_buf[BUFFER_SIZE + 1];
	int		bytes_read;

	read_buf[0] = '\0';
	bytes_read = 1;
	while (!ft_strchr(read_buf, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, read_buf, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			read_buf[bytes_read] = '\0';
			general_buf = ft_join(general_buf, read_buf);
			if (!general_buf)
				return (NULL);
		}
	}
	if (0 > bytes_read)
		return (ft_free(&general_buf));
	return (general_buf);
}

char	*get_next_line(int fd)
{
	static char	*general_buf[OPEN_MAX];
	char		*line;

	general_buf[fd] = ft_read(fd, general_buf[fd]);
	if (!general_buf[fd])
		return (ft_free(&general_buf[fd]));
	line = ft_fetch_line(general_buf[fd]);
	if (!line)
		return (ft_free(&general_buf[fd]));
	general_buf[fd] = ft_cut_line(general_buf[fd]);
	return (line);
}
