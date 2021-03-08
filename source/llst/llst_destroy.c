/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llst_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 12:12:18 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/08 10:26:18 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "carbon/llst.h"

#include <stdlib.h>

void	llst_destroy(t_llst *node, void (*del)(void *))
{
	if (node)
	{
		if (del)
			del(node->data);
		free(node);
	}
}
