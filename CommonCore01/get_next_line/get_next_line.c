/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:09:25 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/12/01 20:31:01 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

char	*ft_free(char **ptr);
char	*ft_strchr(const char *s, int c);
char	*ft_join(char *s1, char *s2);
char	*ft_cut_line(char *general_buf);

static char	*ft_fetch_line(char *general_buf)
{
	char	*line;
	int		l_len;
	int		j;

	l_len = 0;
	j = -1;
	while (general_buf[l_len] != '\n' && general_buf[l_len])
		l_len++;
	line = malloc((l_len + 1 + (general_buf[l_len] == '\n')) * sizeof(char));
	if (!line)
		return (NULL);
	while (++j <= l_len)
		line[j] = general_buf[j];
	if (line[j - 1] == '\n' || !l_len)
		line[j] = '\0';
	return (line);
}

static char	*ft_read(int fd, char *general_buf)
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
	static char	*general_buf = NULL;
	char		*line;

	general_buf = ft_read(fd, general_buf);
	if (!general_buf)
		return (ft_free(&general_buf));
	line = ft_fetch_line(general_buf);
	if (!line)
		return (ft_free(&general_buf));
	general_buf = ft_cut_line(general_buf);
	return (line);
}
