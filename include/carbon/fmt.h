/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:18:44 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/08 10:22:56 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FMT_H
# define FMT_H

# include <stddef.h>
# include <stdint.h>
# include <sys/types.h>

ssize_t	fmt_fprint(int fd, char *str);

ssize_t	fmt_print(char *str);

ssize_t	fmt_fprintln(int fd, char *str);

ssize_t	fmt_println(char *str);

#endif
