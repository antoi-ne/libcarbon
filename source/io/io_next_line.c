/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_next_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:48:49 by ancoulon          #+#    #+#             */
/*   Updated: 2021/02/24 15:21:47 by ancoulon         ###   ########.fr       */
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

static int
	find_nl(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return ((str[i] == '\n') ? i : -1);
}

static int
	retrieve_rest(char **rest, char **line)
{
	int		i;
	char	*tmp;

	if (!*rest)
	{
		if (!(*line = mem_calloc(sizeof(char *))))
			return (-1);
		return (0);
	}
	tmp = *rest;
	i = (find_nl(tmp) > -1) ? find_nl(tmp) : (str_len(tmp) + 1);
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

static int
	manage_nl(char *buffer, char **line, char **rest, int i)
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

static int
	ft_read(int fd, char **rest, char **line)
{
	int		i;
	int		offset;
	char	buffer[CARBON_NL_BUFFSIZE + 1];
	char	*tmp;

	while ((offset = read(fd, buffer, CARBON_NL_BUFFSIZE)) > 0)
	{
		tmp = *line;
		buffer[offset] = '\0';
		if ((i = find_nl(((char *)buffer))) >= 0)
			return (manage_nl((char *)buffer, line, rest, i));
		if (!(*line = str_join(tmp, (char *)buffer)))
			return (-1);
		free(tmp);
	}
	return (offset);
}

int
	io_next_line(int fd, char **line)
{
	static char	*rest[OPEN_MAX + 1];
	int			ret;

	if (CARBON_NL_BUFFSIZE <= 0 || !line || fd < 0 ||
	read(fd, 0, 0) || fd >= OPEN_MAX)
		return (-1);
	if ((ret = retrieve_rest(&(rest[fd]), line)) == -1)
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