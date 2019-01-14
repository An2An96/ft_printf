/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 14:51:09 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/14 16:11:07 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPATCHER_H
# define DISPATCHER_H

# include "inside.h"

const t_formatter	g_dispatcher[] = {
	{ '%', &print_percent },
	{ 'd', &print_number },
	{ 'D', &print_number },
	{ 'i', &print_number },
	{ 'o', &print_octal },
	{ 'O', &print_octal },
	{ 'u', &print_unsigned },
	{ 'U', &print_unsigned },
	{ 'x', &print_hex },
	{ 'X', &print_hex_upper },
	{ 'f', &print_float },
	{ 'F', &print_float },
	{ 'e', &print_efloat },
	{ 'E', &print_efloat },
	{ 'c', &print_char },
	{ 'C', &print_char },
	{ 's', &print_string },
	{ 'S', &print_string },
	{ 'p', &print_pointer },
	{ 'b', &print_binary },
	{ 'n', &write_len },
	{ '\0', NULL }
};

#endif
