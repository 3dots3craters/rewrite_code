/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 13:58:41 by hayelee           #+#    #+#             */
/*   Updated: 2021/07/05 08:49:03 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static	char	*save[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int	result;
	int	read_byte;

	if ((fd < 0) || (fd > OPEN_MAX) || (line == 0) || (BUFFER_SIZE <= 0))
		return (-1);
	result = check_save(&save[fd]);
	while (ft_strchr(save[fd], '\n') < 0)
	{
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte == -1)
			return (-1);
		buf[read_byte] = '\0';
		result = make_save_or_eof(&save[fd], line, buf, read_byte);
		if (result <= 0)
			return (result);
	}
	if (result == 1)
		result = make_line_and_save(&save[fd], line);
	return (result);
}

int	check_save(char **save)
{
	if (*save == NULL)
	{
		*save = ft_strdup("");
		if (*save == NULL)
			return (-1);
	}
	return (1);
}

int	make_last_line(char **save, char **line)
{
	*line = ft_strdup(*save);
	free(*save);
	*save = 0;
	if (*line == NULL)
		return (-1);
	return (0);
}

int	make_save_or_eof(char **save, char **line, char *buf, int read_byte)
{
	int	result;
	char	*tmp;

	result = 1;
	if (read_byte)
	{
		tmp = ft_strjoin(*save, buf);
		free(*save);
		*save = tmp;
		if (*save == NULL)
			result = -1;
	}
	else
		result = make_last_line(save, line);
	return (result);
}

int	make_line_and_save(char **save, char **line)
{
	int	end;
	int	newline;
	char	*tmp;

	end = ft_strlen(*save);
	newline = ft_strchr(*save, '\n');
	*line = ft_substr(*save, 0, newline);
	if (*line == NULL)
	{
		free(*save);
		*save = 0;
		return (-1);
	}
	tmp = ft_substr(*save, newline + 1, end - newline);
	free(*save);
	*save = tmp;
	if (*save == NULL)
		return (-1);
	return (1);
}
