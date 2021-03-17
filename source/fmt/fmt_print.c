/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:18:29 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/08 10:25:28 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "carbon/fmt.h"

#include "carbon/str.h"
#include <unistd.h>

ssize_t	fmt_print(char *str)
{
	return (fmt_fprint(STDOUT_FILENO, str));
}
