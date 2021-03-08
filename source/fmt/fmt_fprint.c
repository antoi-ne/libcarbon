/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_fprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:23:35 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/08 10:25:21 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "carbon/fmt.h"

#include "carbon/str.h"
#include <unistd.h>

ssize_t	fmt_fprint(int fd, char *str)
{
	return (write(fd, str, str_len(str)));
}
