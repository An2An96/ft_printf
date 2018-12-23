/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 14:51:09 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/23 16:55:40 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPATCHER_H
# define DISPATCHER_H

# include "ft_printf.h"

void	print_number(void *value, char flags, int width, int accuracy, char size);
void	print_hex(void *value, char flags, int width, int accuracy, char size);
void	print_char(void *value, char flags, int width, int accuracy, char size);
void	print_string(void *value, char flags, int width, int accuracy, char size);
void	print_pointer(void *value, char flags, int width, int accuracy, char size);

typedef struct	s_formater {
	char		type_specifier;
	void		(*func)(void*, char, int, int, char);
	char		arg_type;
}				t_formatter;

const t_formatter	dispatcher[] = {
	{ 'd', &print_number,	TYPE_INT },
	{ 'X', &print_hex,		TYPE_INT },
	{ 'c', &print_char,		TYPE_CHAR },
	{ 's', &print_string,	TYPE_PTR },
	{ 'p', &print_pointer,	TYPE_PTR }
};

#endif
