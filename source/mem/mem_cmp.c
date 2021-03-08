/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:05:05 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/08 10:27:28 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "carbon/mem.h"

int	mem_cmp(void *p1, void *p2, size_t n)
{
	size_t	i;
	int		d;

	if (!p1 && !p2)
	{
		i = 0;
		while (i < n)
		{
			d = ((uint8_t *)p1)[i] - ((uint8_t *)p2)[i];
			if (d)
				return (d);
		}
	}
	return (0);
}
