/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:09:16 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/23 20:10:38 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include "libft.h"

# define TYPE_INT		1
# define TYPE_CHAR		2
# define TYPE_PTR		3

# define FLAG_MINUS		1
# define FLAG_PLUS		2
# define FLAG_SPACE		4
# define FLAG_OCTOP		8
# define FLAG_ZERO		16

typedef enum	e_sp_size
{
	SIZE_NONE,
	SIZE_l,
	SIZE_hh,
	SIZE_h,
	SIZE_ll,
	SIZE_L
}				t_sp_size;

int				ft_printf(const char *format, ...);

void			print_number(
	void *value, char flags, int width, int accuracy, char size);
void			print_octal(
	void *value, char flags, int width, int accuracy, char size);
void			print_unsigned(
	void *value, char flags, int width, int accuracy, char size);
void			print_hex(
	void *value, char flags, int width, int accuracy, char size);
void			print_hex_lower(
	void *value, char flags, int width, int accuracy, char size);
void			print_float(
	void *value, char flags, int width, int accuracy, char size);
void			print_char(
	void *value, char flags, int width, int accuracy, char size);
void			print_string(
	void *value, char flags, int width, int accuracy, char size);
void			print_pointer(
	void *value, char flags, int width, int accuracy, char size);

typedef struct	s_formater {
	char		type_specifier;
	void		(*func)(void*, char, int, int, char);
	char		arg_type;
}				t_formatter;

#endif
