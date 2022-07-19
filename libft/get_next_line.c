/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:45:47 by khovakim          #+#    #+#             */
/*   Updated: 2022/07/08 13:47:27 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strjoin_free(char *save, char *ptr)
{
	char	*line;

	if (!ptr)
		return (NULL);
	line = ft_strjoin(save, ptr);
	if (save)
		free(save);
	return (line);
}

static int	ft_strlen_n(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\n')
		i++;
	return (i);
}

static char	*ft_get_line(char **save)
{
	char	*new_line;
	char	*del;

	if (!(*save))
		return (NULL);
	new_line = NULL;
	if (ft_strchr(*save, '\n'))
	{
		new_line = ft_substr(*save, 0, ft_strlen_n(*save) + 1);
		del = ft_strdup(*save + ft_strlen_n(*save) + 1);
		if (*del == '\0')
		{
			free(del);
			del = NULL;
		}
		free(*save);
		*save = del;
	}
	return (new_line);
}

static char	*ft_save_line(int fd, char **save, char *line)
{
	int		byte;
	char	ptr[BUFFER_SIZE + 1];

	byte = 1;
	while (byte != 0)
	{
		byte = read(fd, ptr, BUFFER_SIZE);
		if (byte == -1)
			return (NULL);
		ptr[byte] = '\0';
		if (byte > 0)
			*save = ft_strjoin_free(*save, ptr);
		line = ft_get_line(save);
		if (line)
			return (line);
	}
	line = ft_strdup(*save);
	free(*save);
	*save = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*save = NULL;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 65536)
		return (NULL);
	line = ft_get_line(&save);
	if (line)
		return (line);
	line = ft_save_line(fd, &save, line);
	return (line);
}
