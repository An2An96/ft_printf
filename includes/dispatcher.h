/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 14:51:09 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/24 14:55:29 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPATCHER_H
# define DISPATCHER_H

#include "ft_printf.h"

const t_formatter	g_dispatcher[] = {
	{ 'd', &print_number, TYPE_INT },
	{ 'i', &print_number, TYPE_INT },
	{ 'o', &print_octal, TYPE_INT },
	{ 'u', &print_unsigned, TYPE_INT },
	{ 'x', &print_hex_lower, TYPE_INT },
	{ 'X', &print_hex, TYPE_INT },
	{ 'c', &print_char, TYPE_CHAR },
	{ 's', &print_string, TYPE_PTR },
	{ 'p', &print_pointer, TYPE_PTR },
	{ '\0', NULL, 0 }
};

#endif
