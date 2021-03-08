/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:46:09 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/08 10:23:12 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_H
# define MEM_H

# include <stddef.h>
# include <stdint.h>

void	*mem_set(void *p, uint8_t c, size_t size);

void	*mem_setalloc(size_t size, uint8_t c);

void	*mem_calloc(size_t size);

void	*mem_cpy(void *d, void *s, size_t n);

int		mem_cmp(void *p1, void *p2, size_t n);

#endif
