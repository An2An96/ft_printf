/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:09:16 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/24 19:28:22 by rschuppe         ###   ########.fr       */
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
# define TYPE_FLOAT		4

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

typedef struct	s_value_types {
	size_t		p_value;
	int			i_value;
	double		d_value;
	long double ld_value;
}				t_value_types;

typedef struct	s_spec {
	char	flags;
	int		width;
	int		accuracy;
	char	size;
}				t_spec;

typedef struct	s_formater {
	char		type_specifier;
	void		(*func)(void*, t_spec);
	char		arg_type;
}				t_formatter;

int				ft_printf(const char *format, ...);

void			print_number(void *value, t_spec spec);
void			print_octal(void *value, t_spec spec);
void			print_unsigned(void *value, t_spec spec);
void			print_hex(void *value, t_spec spec);
void			print_hex_lower(void *value, t_spec spec);
void			print_float(void *value, t_spec spec);
void			print_char(void *value, t_spec spec);
void			print_string(void *value, t_spec spec);
void			print_pointer(void *value, t_spec spec);

#endif
