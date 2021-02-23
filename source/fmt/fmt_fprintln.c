/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_fprintln.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:26:10 by ancoulon          #+#    #+#             */
/*   Updated: 2021/02/23 11:48:27 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "carbon/fmt.h"
#include "carbon/str.h"
#include "unistd.h"

ssize_t
	fmt_fprintln(int fd, char *str)
{
	ssize_t	s;
	s = write(fd, str, str_len(str));
	s += write(fd, "\n", 1);
	return (s);
}
