/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_sub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:09:24 by ancoulon          #+#    #+#             */
/*   Updated: 2021/02/24 15:23:55 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "carbon/str.h"

#include "carbon/mem.h"

char*
	str_sub(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	size_t	s_newlen;
	char	*str;

	if (!s)
		return (NULL);
	s_len = str_len(s);
	if (s_len < start)
		return (str_dup(""));
	i = 0;
	s_newlen = (start + len < s_len) ? len : s_len - start;
	str = mem_calloc(sizeof(char) * (s_newlen + 1));
	while (str && s[start + i] && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
