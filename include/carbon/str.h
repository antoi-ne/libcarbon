/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:53:40 by ancoulon          #+#    #+#             */
/*   Updated: 2021/02/23 19:47:30 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

# include <stddef.h>
# include <stdint.h>

/*
**  size_t *str_len(char *s)
**
** DESCRIPTION: str_len() computes the number of characters in the string s.
** RETURN VALUE: str_len() returns the length of s, or 0 if s is NULL.
*/
size_t	str_len(char *s);

/*
** char *str_cpy(char *d, char *s)
**
** DESCRIPTION: str_cpy() copies the string s into the string d.
** RETURN VALUE: str_cpy() returns d.
*/
char	*str_cpy(char *d, char *s);

char	*str_ncpy(char *d, char *s, size_t len);

/*
** char *str_dup(char *s)
**
** DESCRIPTION: str_dup() allocates and returns a copy of s.
** RETURN VALUE: str_dup() returns the newly allocated copy of s.
*/
char	*str_dup(char *s);

char	*str_ndup(char *s, size_t len);

char	**str_split(char *s, char c);

char	**str_split_free(char **strs);

#endif
