/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llst_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:54:23 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/08 10:26:32 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "carbon/llst.h"
#include <stdio.h>

t_llst	*llst_pop(t_llst **lst)
{
	t_llst	*node;
	t_llst	*tail;

	if (!lst || !*lst)
		return (NULL);
	node = *lst;
	if (!node->next)
	{
		*lst = NULL;
		return (node);
	}
	while (node && node->next && node->next->next)
		node = node->next;
	tail = node->next;
	node->next = NULL;
	return (tail);
}
