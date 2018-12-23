/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 14:51:09 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/23 17:27:09 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPATCHER_H
# define DISPATCHER_H

# define TYPE_INT		1
# define TYPE_CHAR		2
# define TYPE_PTR		3

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
	{ 'i', &print_number,	TYPE_INT },
	{ 'X', &print_hex,		TYPE_INT },
	{ 'c', &print_char,		TYPE_CHAR },
	{ 's', &print_string,	TYPE_PTR },
	{ 'p', &print_pointer,	TYPE_PTR }
};

#endif
