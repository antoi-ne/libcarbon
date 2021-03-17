/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_ndup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:09:46 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/08 10:28:25 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "carbon/str.h"

#include "carbon/mem.h"

char	*str_ndup(char *s, size_t len)
{
	char	*dup;
	size_t	max_len;

	max_len = str_len(s);
	if (len < max_len)
		max_len = len;
	dup = mem_calloc(max_len);
	str_ncpy(dup, s, len + 1);
	return (dup);
}
