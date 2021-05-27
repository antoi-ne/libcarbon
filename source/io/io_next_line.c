/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_next_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:48:49 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/27 12:35:11 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "carbon/io.h"

#include "carbon/mem.h"
#include "carbon/str.h"
#include <limits.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

static char	*endl_check(char *str)
{
	while (str && *str)
	{
		if (*str == '\n')
			return (str);
		str++;
	}
	return (NULL);
}

static int	ft_desaloc(char **rest)
{
	if (rest && *rest)
	{
		free(*rest);
		*rest = NULL;
	}
	return (-1);
}

static int	line_packager(char **line, char **rest)
{
	char	*endl_found;

	endl_found = endl_check(*rest);
	if (endl_found)
	{
		*line = str_ndup(*rest, endl_found - *rest);
		if (!(*line))
			return (-1);
		endl_found = str_dup(endl_found + 1);
		if (!endl_found)
			return (-1);
		free(*rest);
		*rest = endl_found;
		return (1);
	}
	return (0);
}

static int	body(char **line, char *read_buff, char **rest, int fd)
{
	int		read_size;
	int		package_return;

	read_size = read(fd, read_buff, BUFFER_SIZE);
	while (read_size > 0)
	{
		read_buff[read_size] = '\0';
		*rest = str_join(*rest, read_buff);
		if ((*rest) == NULL)
			return (ft_desaloc(rest));
		package_return = line_packager(line, rest);
		if (package_return == 1)
			return (1);
		else if (package_return == -1)
			return (ft_desaloc(rest));
		read_size = read(fd, read_buff, BUFFER_SIZE);
	}
	if (read_size <= 0)
		return (ft_desaloc(rest));
	*line = str_dup(*rest);
	ft_desaloc(rest);
	return (0);
}

int	io_next_line(int fd, char **line)
{
	char			read_buff[BUFFER_SIZE + 1];
	static char		*rest[OPEN_MAX];
	int				package_return;

	if (!line || fd >= OPEN_MAX || BUFFER_SIZE < 1)
		return (-1);
	*line = NULL;
	if (rest[fd])
	{
		package_return = line_packager(line, &rest[fd]);
		if (package_return == 1)
			return (1);
		else if (package_return == -1)
			return (ft_desaloc(&rest[fd]));
	}
	return (body(line, read_buff, &rest[fd], fd));
}
