/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 23:00:51 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/12/01 20:31:17 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] == (unsigned char)c)
			return ((char *) &s[i]);
	if (!(unsigned char)c)
		return ((char *) &s[i]);
	return (NULL);
}

static size_t	ft_strlen(char *str)
{
	size_t	size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

char	*ft_join(char *s1, char *s2)
{
	char	*joined_str;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	joined_str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!joined_str)
		return (ft_free(&s1));
	i = -1;
	while (s1[++i])
		joined_str[i] = s1[i];
	j = -1;
	while (s2[++j])
		joined_str[i + j] = s2[j];
	joined_str[i + j] = '\0';
	free(s1);
	return (joined_str);
}

char	*ft_cut_line(char *general_buf)
{
	char	*temp;
	int		l_len;
	int		j;

	l_len = 0;
	j = -1;
	while (general_buf[l_len] != '\n' && general_buf[l_len])
		l_len++;
	if (!general_buf[l_len] || !general_buf[l_len + 1])
		return (ft_free(&general_buf));
	temp = (char *)malloc((ft_strlen(general_buf) - l_len + 1) * sizeof(char));
	if (!temp)
		return (ft_free(&general_buf));
	l_len++;
	while (general_buf[l_len + ++j])
		temp[j] = general_buf[l_len + j];
	temp[j] = '\0';
	free(general_buf);
	return (temp);
}
