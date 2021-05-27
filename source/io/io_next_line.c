/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_next_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:48:49 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/27 12:54:02 by ancoulon         ###   ########.fr       */
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

// static char	*endl_check(char *str)
// {
// 	while (str && *str)
// 	{
// 		if (*str == '\n')
// 			return (str);
// 		str++;
// 	}
// 	return (NULL);
// }

// static int	ft_desaloc(char **rest)
// {
// 	if (rest && *rest)
// 	{
// 		free(*rest);
// 		*rest = NULL;
// 	}
// 	return (-1);
// }

// static int	line_packager(char **line, char **rest)
// {
// 	char	*endl_found;

// 	endl_found = endl_check(*rest);
// 	if (endl_found)
// 	{
// 		*line = str_ndup(*rest, endl_found - *rest);
// 		if (!(*line))
// 			return (-1);
// 		endl_found = str_dup(endl_found + 1);
// 		if (!endl_found)
// 			return (-1);
// 		free(*rest);
// 		*rest = endl_found;
// 		return (1);
// 	}
// 	return (0);
// }

// static int	body(char **line, char *read_buff, char **rest, int fd)
// {
// 	int		read_size;
// 	int		package_return;

// 	read_size = read(fd, read_buff, BUFFER_SIZE);
// 	while (read_size > 0)
// 	{
// 		read_buff[read_size] = '\0';
// 		*rest = str_join(*rest, read_buff);
// 		if ((*rest) == NULL)
// 			return (ft_desaloc(rest));
// 		package_return = line_packager(line, rest);
// 		if (package_return == 1)
// 			return (1);
// 		else if (package_return == -1)
// 			return (ft_desaloc(rest));
// 		read_size = read(fd, read_buff, BUFFER_SIZE);
// 	}
// 	if (read_size <= 0)
// 		return (ft_desaloc(rest));
// 	*line = str_dup(*rest);
// 	ft_desaloc(rest);
// 	return (0);
// }

// int	io_next_line(int fd, char **line)
// {
// 	char			read_buff[BUFFER_SIZE + 1];
// 	static char		*rest[OPEN_MAX];
// 	int				package_return;

// 	if (!line || fd >= OPEN_MAX || BUFFER_SIZE < 1)
// 		return (-1);
// 	*line = NULL;
// 	if (rest[fd])
// 	{
// 		package_return = line_packager(line, &rest[fd]);
// 		if (package_return == 1)
// 			return (1);
// 		else if (package_return == -1)
// 			return (ft_desaloc(&rest[fd]));
// 	}
// 	return (body(line, read_buff, &rest[fd], fd));
// }


static	int	ft_findnl(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return ((str[i] == '\n') ? i : -1);
}

static int	ft_retrieve_rest(char **rest, char **line)
{
	int		i;
	char	*tmp;

	if (!*rest)
	{
		if (!(*line = mem_calloc(1)))
			return (-1);
		return (0);
	}
	tmp = *rest;
	i = (ft_findnl(tmp) > -1) ? ft_findnl(tmp) : (str_len(tmp) + 1);
	if (!(*line = str_sub(tmp, 0, i)))
		return (-1);
	if ((int)str_len(tmp) > i && tmp[i] == '\n')
	{
		if (!(*rest = str_sub(tmp, ++i, str_len(tmp))))
			return (-1);
		free(tmp);
		return (1);
	}
	free(tmp);
	*rest = NULL;
	return (0);
}

static int	ft_manage_nl(char *buffer, char **line, char **rest, int i)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = *line;
	if (!(tmp2 = str_sub((char *)buffer, 0, i)))
		return (0);
	if (!(*line = str_join(tmp1, tmp2)))
		return (-1);
	free(tmp1);
	free(tmp2);
	tmp1 = *rest;
	if (!(tmp2 = str_sub((char *)buffer, ++i, str_len((char *)buffer))))
		return (-1);
	if (!(*rest = str_join(tmp1, tmp2)))
		return (-1);
	free(tmp1);
	free(tmp2);
	return (1);
}

static int	ft_read(int fd, char **rest, char **line)
{
	int		i;
	int		offset;
	char	buffer[BUFFER_SIZE + 1];
	char	*tmp;

	while ((offset = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		tmp = *line;
		buffer[offset] = '\0';
		if ((i = ft_findnl(((char *)buffer))) >= 0)
			return (ft_manage_nl((char *)buffer, line, rest, i));
		if (!(*line = str_join(tmp, (char *)buffer)))
			return (-1);
		free(tmp);
	}
	return (offset);
}

int			io_next_line(int fd, char **line)
{
	static char	*rest[OPEN_MAX + 1];
	int			ret;

	if (BUFFER_SIZE <= 0 || !line || fd < 0 ||
	read(fd, 0, 0) || fd >= OPEN_MAX)
		return (-1);
	if ((ret = ft_retrieve_rest(&(rest[fd]), line)) == -1)
		return (-1);
	if (!ret)
	{
		if ((ret = ft_read(fd, &(rest[fd]), line)) == -1)
			return (-1);
		return (ret);
	}
	else
		return (1);
}