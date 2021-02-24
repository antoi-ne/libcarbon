/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_cpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 19:08:49 by ancoulon          #+#    #+#             */
/*   Updated: 2021/02/23 19:32:06 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "carbon/str.h"

char*
	str_cpy(char *d, char *s)
{
	size_t	i;

	if (d && s)
	{
		i = 0;
		while (s[i])
		{
			d[i] = s[i];
			i++;
		}
		d[i] = '\0';
	}
	return (d);
}
