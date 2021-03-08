/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_setalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:53:33 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/08 10:27:41 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "carbon/mem.h"

#include <stdlib.h>

void	*mem_setalloc(size_t size, uint8_t c)
{
	void	*p;

	p = malloc(size);
	if (p)
		mem_set(p, c, size);
	return (p);
}
