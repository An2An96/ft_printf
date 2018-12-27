/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 14:51:09 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/27 23:51:53 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPATCHER_H
# define DISPATCHER_H

# include "inside.h"

const t_formatter	g_dispatcher[] = {
	{ '%', &print_percent, TYPE_NONE },
	{ 'd', &print_number, TYPE_INT },
	{ 'D', &print_number, TYPE_INT },
	{ 'i', &print_number, TYPE_INT },
	{ 'o', &print_octal, TYPE_UNSIGNED },
	{ 'O', &print_octal, TYPE_UNSIGNED },
	{ 'u', &print_unsigned, TYPE_UNSIGNED },
	{ 'U', &print_unsigned, TYPE_UNSIGNED },
	{ 'x', &print_hex, TYPE_UNSIGNED },
	{ 'X', &print_hex_upper, TYPE_UNSIGNED },
	{ 'f', &print_float, TYPE_DOUBLE },
	{ 'F', &print_float, TYPE_DOUBLE },
	{ 'c', &print_char, TYPE_INT },
	{ 'C', &print_char, TYPE_INT },
	{ 's', &print_string, TYPE_PTR },
	{ 'S', &print_string, TYPE_PTR },
	{ 'p', &print_pointer, TYPE_PTR },
	{ 'b', &print_binary, TYPE_INT },
	{ 'n', &write_len, TYPE_PTR },
	{ '\0', NULL, 0 }
};

#endif
