/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llst.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 19:33:09 by ancoulon          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/03/17 15:33:17 by ancoulon         ###   ########.fr       */
=======
/*   Updated: 2021/03/08 10:22:42 by ancoulon         ###   ########.fr       */
>>>>>>> a79ae0dc840ab1c31bef88d81dad3bc6786a69b8
/*                                                                            */
/* ************************************************************************** */

#ifndef LLST_H
# define LLST_H

# include <stddef.h>
# include <stdint.h>

typedef struct	s_llst
{
	void			*data;
	struct s_llst	*next;
}				t_llst;

t_llst			*llst_new(void *data);

size_t			llst_len(t_llst *node);

t_llst			*llst_tail(t_llst *node);

void			llst_push(t_llst **lst, t_llst *node);

t_llst			*llst_pop(t_llst **lst);

void			llst_unshift(t_llst **lst, t_llst *node);

t_llst			*llst_shift(t_llst **lst);

void			llst_destroy(t_llst *node, void (*del)(void *));

void			llst_destroyl(t_llst **lst, void (*del)(void *));

#endif
