/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:18:44 by ancoulon          #+#    #+#             */
/*   Updated: 2021/02/23 14:03:25 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FMT_H
# define FMT_H

# include <stddef.h>
# include <stdint.h>
# include <sys/types.h>

/*
** ssize_t fmt_fprint(int fd, char *str)
**
** DESCRIPTION: fmt_fprint() prints the string str in the file fd.
** RETURN VALUE: fmt_fprint() returns the number of printed characters,
** or -1 in case of an error.
*/
ssize_t	fmt_fprint(int fd, char *str);

/*
** ssize_t fmt_print(char *str)
**
** DESCRIPTION: fmt_print() prints the string str in STDOUT.
** RETURN VALUE: fmt_print() returns the number of printed characters,
** or -1 in case of an error.
*/
ssize_t	fmt_print(char *str);

/*
** ssize_t fmt_fprintln(int fd, char *str)
**
** DESCRIPTION: fmt_fprintln() prints the string str followed by a \n
** in the file fd.
** RETURN VALUE: fmt_fprintln() returns the number of printed characters,
** or -1 in case of an error.
*/
ssize_t	fmt_fprintln(int fd, char *str);

/*
** ssize_t fmt_println(int fd, char *str)
**
** DESCRIPTION: fmt_println() prints the string str followed by a \n
** in STDOUT
** RETURN VALUE: fmt_println() returns the number of printed characters,
** or -1 in case of an error.
*/
ssize_t	fmt_println(char *str);

#endif
