/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llst_unshift.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:51:05 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/08 10:26:50 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "carbon/llst.h"

void	llst_unshift(t_llst **lst, t_llst *node)
{
	if (lst && node)
	{
		node->next = *lst;
		*lst = node;
	}
}
