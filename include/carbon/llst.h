/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llst.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 19:33:09 by ancoulon          #+#    #+#             */
/*   Updated: 2021/02/25 12:11:27 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LLST_H
# define LLST_H

# include <stddef.h>
# include <stdint.h>

/*
** t_llst: struct s_llst
**
** DESCRIPTION: t_llst represents a single node of a linked list.
** ATTRIBUTES:
** - void *data: content of the list element.
** - struct s_llst	*next: pointer to the next list element.
*/
typedef struct	s_llst
{
	void			*data;
	struct s_llst	*next;
}				t_llst;

/*
** t_llst *llst_new(void *data)
**
** DESCRIPTION: llst_new() allocates a new list element and sets its data
** attribute to the data parameter.
** RETURN VALUE: llst_new() returns the newly allocated t_llist element.
*/
t_llst	*llst_new(void *data);

t_llst	*llst_tail(t_llst *node);

void	llst_push(t_llst **lst, t_llst *node);

t_llst	*llst_pop(t_llst **lst);

void	llst_unshift(t_llst **lst, t_llst *node);

t_llst	*llst_shift(t_llst **lst);

#endif
