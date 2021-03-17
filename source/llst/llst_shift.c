/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llst_shift.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 12:03:12 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/08 10:26:41 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "carbon/llst.h"

t_llst	*llst_shift(t_llst **lst)
{
	t_llst	*head;

	if (!lst || !*lst)
		return (NULL);
	head = *lst;
	*lst = head->next;
	return (head);
}
