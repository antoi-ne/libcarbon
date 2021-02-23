/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:46:09 by ancoulon          #+#    #+#             */
/*   Updated: 2021/02/06 16:17:03 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_H
# define MEM_H

# include <stddef.h>
# include <stdint.h>

/*
** void *mem_set(void *p, char c, size_t size)
**
** DESCRIPTION: mem_set() writes size bytes of c to the pointer p.
** RETURN VALUE: mem_set() returns its first argument.
*/
void	*mem_set(void *p, uint8_t c, size_t size);

/*
** void *mem_setalloc(size_t size, uint8_t c)
**
** DESCRIPTION: mem_setalloc() allocates size bytes of memory and
** sets them to byte c.
** RETURN VALUE: If successfull, mem_setalloc() returns a pointer to the
** allocated memory. Else, NULL is returned.
*/
void	*mem_setalloc(size_t size, uint8_t c);

/*
** void *mem_setalloc(size_t size)
**
** DESCRIPTION: mem_calloc() allocates size bytes of memory and
** sets them to 0.
** RETURN VALUE: If successfull, mem_calloc() returns a pointer to the
** allocated memory. Else, NULL is returned.
*/
void	*mem_calloc(size_t size);

/*
** void *mem_cpy(void *d, void *s, size_t n)
**
** DESCRIPTION: mem_cpy copies n bytes of memory from s to d.
** RETURN VALUE: mem_cpy() returns its first argument.
*/
void	*mem_cpy(void *d, void *s, size_t n);

/*
** int mem_cmp(void *p1, void *p2, size_t n)
**
** DESCRIPTION: mem_cmp() compares n bytes of p1 and p2.
** RETURN VALUE: If p1 and p2 are identical, 0 will be returned. Else,
** the value differnce between the first non-identical bytes will be
** returned.
*/
int		mem_cmp(void *p1, void *p2, size_t n);

#endif
