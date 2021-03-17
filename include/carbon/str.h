/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:53:40 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/08 10:23:24 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

# include <stddef.h>
# include <stdint.h>

size_t	str_len(char *s);

char	*str_cpy(char *d, char *s);

char	*str_ncpy(char *d, char *s, size_t len);

char	*str_cat(char *d, char *s);

int		str_cmp(char *s1, char *s2);

char	*str_dup(char *s);

char	*str_ndup(char *s, size_t len);

char	*str_sub(char *s, unsigned int start, size_t len);

char	*str_join(char *s1, char *s2);

char	**str_split(char *s, char c);

char	**str_split_free(char **strs);

#endif
