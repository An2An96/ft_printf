/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 14:51:09 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/26 17:14:46 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPATCHER_H
# define DISPATCHER_H

# include "ft_printf.h"

const t_formatter	g_dispatcher[] = {
	{ '%', &print_percent, TYPE_NONE },
	{ 'd', &print_number, TYPE_INT },
	{ 'i', &print_number, TYPE_INT },
	{ 'o', &print_octal, TYPE_UNSIGNED },
	{ 'u', &print_unsigned, TYPE_UNSIGNED },
	{ 'U', &print_unsigned, TYPE_UNSIGNED },
	{ 'x', &print_hex, TYPE_UNSIGNED },
	{ 'X', &print_hex_upper, TYPE_UNSIGNED },
	{ 'f', &print_float, TYPE_DOUBLE },
	{ 'c', &print_char, TYPE_INT },
	{ 's', &print_string, TYPE_PTR },
	{ 'p', &print_pointer, TYPE_PTR },
	{ '\0', NULL, 0 }
};

#endif
