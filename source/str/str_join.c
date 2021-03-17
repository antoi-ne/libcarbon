/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:55:51 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/08 10:28:12 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "carbon/str.h"

#include "carbon/mem.h"

char	*str_join(char *s1, char *s2)
{
	char	*str;
	size_t	len;

	len = str_len(s1) + str_len(s2);
	str = (char *)mem_calloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str_cat(str, s1);
	str_cat(str, s2);
	return (str);
}
