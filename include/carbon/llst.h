/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llst.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 19:33:09 by ancoulon          #+#    #+#             */
/*   Updated: 2021/01/14 19:41:59 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LLST_H
# define LLST_H

# include <stddef.h>
# include <stdint.h>

typedef struct	s_llst
{
	void			*data;
	struct s_node	*next;
}				t_llst;

t_llst	*llst_new(void *data);

#endif
