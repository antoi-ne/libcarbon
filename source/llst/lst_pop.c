/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_pop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:54:23 by ancoulon          #+#    #+#             */
/*   Updated: 2021/02/25 12:02:26 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "carbon/llst.h"

t_llst*
	llst_pop(t_llst **lst)
{
	t_llst	*tail;
	
	if (!lst || !*lst)
		return (NULL);
	while (*lst && (*lst)->next)
		*lst = (*lst)->next;
	tail = (*lst)->next;
	(*lst)->next = NULL;
	return (tail);
}
