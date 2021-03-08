/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_cat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:56:47 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/08 10:27:54 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "carbon/str.h"

char	*str_cat(char *d, char *s)
{
	size_t	i;
	size_t	len;

	if (!d)
		return (s);
	if (!s)
		return (d);
	i = 0;
	len = str_len(d);
	while (s[i])
	{
		d[len + i] = s[i];
		i++;
	}
	d[len + i] = '\0';
	return (d);
}
