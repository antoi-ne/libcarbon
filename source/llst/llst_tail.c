/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llst_tail.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:26:21 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/08 10:26:58 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "carbon/llst.h"

t_llst	*llst_tail(t_llst *node)
{
	while (node && node->next)
		node = node->next;
	return (node);
}
