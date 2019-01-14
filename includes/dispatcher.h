/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 14:51:09 by rschuppe          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/01/14 18:09:41 by anorjen          ###   ########.fr       */
=======
/*   Updated: 2019/01/14 18:31:57 by rschuppe         ###   ########.fr       */
>>>>>>> local-master
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPATCHER_H
# define DISPATCHER_H

# include "inside.h"

const t_formatter	g_dispatcher[] = {
	{ '%', &print_percent },
	{ 'd', &print_number },
	{ 'D', &print_long_number },
	{ 'i', &print_number },
	{ 'o', &print_octal },
	{ 'O', &print_long_octal },
	{ 'u', &print_unsigned },
	{ 'U', &print_long_unsigned },
	{ 'x', &print_hex },
	{ 'X', &print_hex_upper },
	{ 'f', &print_float },
	{ 'F', &print_float },
	{ 'e', &print_efloat },
	{ 'E', &print_efloat_upper },
	{ 'a', &print_afloat },
	{ 'A', &print_afloat_upper },
	{ 'c', &print_char },
	{ 'C', &print_char },
	{ 's', &print_string },
	{ 'S', &print_long_string },
	{ 'p', &print_pointer },
	{ 'b', &print_binary },
	{ 'n', &write_len },
	{ '\0', NULL }
};

#endif
