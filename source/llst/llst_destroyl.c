/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llst_destroyl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 12:17:04 by ancoulon          #+#    #+#             */
/*   Updated: 2021/02/25 12:24:29 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "carbon/llst.h"

void
	llst_destroyl(t_llst **lst, void (*del)(void *))
{
	t_llst	*cursor;

	while (lst && *lst)
	{
		cursor = (*lst)->next;
		llst_destroy(*lst, del);
		*lst = cursor;
	}
	if (lst)
		*lst = NULL;
}
