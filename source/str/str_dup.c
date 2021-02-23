/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 19:05:12 by ancoulon          #+#    #+#             */
/*   Updated: 2021/02/23 11:49:24 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "carbon/str.h"
#include "carbon/mem.h"

char*
	str_dup(char *s)
{
	char	*cpy;

	cpy = mem_setalloc(str_len(s), '\0');
	str_cpy(cpy, s);
	return (cpy);
}
