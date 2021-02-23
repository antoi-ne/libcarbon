/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llst_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 19:38:06 by ancoulon          #+#    #+#             */
/*   Updated: 2021/02/23 11:48:51 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "carbon/llst.h"
#include "carbon/mem.h"

t_llst*
	llst_new(void *data)
{
	t_llst	*el;

	el = mem_setalloc(sizeof(t_llst), 0);
	if (el)
		el->data = data;
	return (el);
}
