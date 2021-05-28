/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_next_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:48:49 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/28 13:54:48 by ancoulon         ###   ########.fr       */
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

static	int	ft_findnl(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (i);
	return (-1);
}

int	ft_retrieve_rest(char **rest, char **line)
{
	int		i;
	char	*tmp;

	if (!*rest)
	{
		*line = mem_calloc(1);
		if (!line)
			return (-1);
		return (0);
	}
	tmp = *rest;
	if (ft_findnl(tmp) > -1)
		i = ft_findnl(tmp);
	else
		i = str_len(tmp) + 1;
	*line = str_sub(tmp, 0, i);
	if (!*line)
		return (-1);
	return (ft_retrieve_rest_util(rest, &i, &tmp));
}

static int	ft_manage_nl(char *buffer, char **line, char **rest, int i)
{
	char	*tmp[2];

	tmp[0] = *line;
	tmp[1] = str_sub((char *)buffer, 0, i);
	if (!tmp[1])
		return (0);
	*line = str_join(tmp[0], tmp[1]);
	if (!*line)
		return (-1);
	free(tmp[0]);
	free(tmp[1]);
	tmp[0] = *rest;
	tmp[1] = str_sub((char *)buffer, ++i, str_len((char *)buffer));
	if (!tmp[1])
		return (-1);
	*rest = str_join(tmp[0], tmp[1]);
	if (!*rest)
		return (-1);
	free(tmp[0]);
	free(tmp[1]);
	return (1);
}

static int	ft_read(int fd, char **rest, char **line)
{
	int		i;
	int		offset;
	char	buffer[BUFFER_SIZE + 1];
	char	*tmp;

	offset = read(fd, buffer, BUFFER_SIZE);
	while (offset > 0)
	{
		tmp = *line;
		buffer[offset] = '\0';
		i = ft_findnl(((char *)buffer));
		if (i >= 0)
			return (ft_manage_nl((char *)buffer, line, rest, i));
		*line = str_join(tmp, (char *)buffer);
		if (!*line)
			return (-1);
		free(tmp);
		offset = read(fd, buffer, BUFFER_SIZE);
	}
	return (offset);
}

int	io_next_line(int fd, char **line)
{
	static char	*rest[OPEN_MAX + 1];
	int			ret;

	if (BUFFER_SIZE <= 0 || !line || fd < 0
		|| read(fd, 0, 0) || fd >= OPEN_MAX)
		return (-1);
	ret = ft_retrieve_rest(&(rest[fd]), line);
	if (ret == -1)
		return (-1);
	if (!ret)
	{
		ret = ft_read(fd, &(rest[fd]), line);
		if (ret == -1)
			return (-1);
		return (ret);
	}
	else
		return (1);
}
