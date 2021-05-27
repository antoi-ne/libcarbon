/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 18:47:43 by ancoulon          #+#    #+#             */
/*   Updated: 2021/05/27 12:32:07 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "carbon/str.h"

#include "carbon/mem.h"
#include <stdlib.h>
#include <stdio.h>

static size_t	token_counter(char *s, char c)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		counter++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (counter);
}

char	**str_split_free(char **strs)
{
	size_t	i;

	i = 0;
	if (strs)
	{
		while (strs[i])
		{
			free(strs[i]);
			i++;
		}
		free(strs);
	}
	return (NULL);
}

char	**str_split(char *s, char c)
{
	char	**strs;
	size_t	counter;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	counter = token_counter(s, c);
	strs = mem_calloc(sizeof(char *) * (counter + 1));
	counter = 0;
	i = -1;
	while (strs && s[++i])
	{
		if (s[i] == c)
			continue ;
		j = 0;
		while (s[i + j] && s[i + j] != c)
			j++;
		strs[counter++] = str_ndup(s + i, j);
		if (!strs[counter - 1])
			return (str_split_free(strs));
		i += j - 1;
	}
	return (strs);
}
