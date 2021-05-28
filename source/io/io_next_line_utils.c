/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_next_line_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 13:45:04 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/28 13:54:39 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "carbon/mem.h"
#include "carbon/str.h"
#include <limits.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int	ft_retrieve_rest_util(char **rest, int *i, char **tmp)
{
	if ((int)str_len(*tmp) > *i && (*tmp)[*i] == '\n')
	{
		*rest = str_sub(*tmp, ++(*i), str_len(*tmp));
		if (!*rest)
			return (-1);
		free(*tmp);
		return (1);
	}
	free(*tmp);
	*rest = NULL;
	return (0);
}
