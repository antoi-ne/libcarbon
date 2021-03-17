/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_println.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:28:20 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/08 10:25:30 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "carbon/fmt.h"

#include "carbon/str.h"
#include <unistd.h>

ssize_t	fmt_println(char *str)
{
	return (fmt_fprintln(STDOUT_FILENO, str));
}
