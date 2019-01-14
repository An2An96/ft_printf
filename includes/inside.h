/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inside.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:09:16 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/14 17:59:50 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INSIDE_H
# define FT_INSIDE_H

# include <stdio.h>
# include <stdarg.h>
# include "libft.h"

# define CHECK_FLAG(f)	(spec->flags & f)

# define FLAG_MINUS		1
# define FLAG_PLUS		2
# define FLAG_SPACE		4
# define FLAG_OCTOP		8
# define FLAG_ZERO		16

typedef enum	e_sp_size
{
	SIZE_NONE,
	SIZE_L,
	SIZE_l,
	SIZE_ll,
	SIZE_hh,
	SIZE_h,
	SIZE_j,
	SIZE_z
}				t_sp_size;

typedef struct	s_value_types {
	void		*p_value;
	long long	l_value;
	double		d_value;
	long double ld_value;
	ssize_t		z_value;
}				t_value_types;

typedef struct	s_spec {
	char	flags;
	int		width;
	int		accuracy;
	char	size;
}				t_spec;

typedef struct	s_formater {
	char		type_specifier;
	int			(*func)(va_list*, t_spec*, int*);
}				t_formatter;

int				find_specifier(const char ch);
void			parse_spec_body(char *body, va_list *ap, t_spec *spec);
int				is_spec_body_char(char ch);
char			get_flags(char **body);
int				get_accuracy(char *body, va_list *ap);
char			get_size(char *body);

int				write_len(va_list *ap, t_spec *spec, int *len);
int				print_percent(va_list *ap, t_spec *spec, int *len);
int				print_number(va_list *ap, t_spec *spec, int *len);
int				print_octal(va_list *ap, t_spec *spec, int *len);
int				print_unsigned(va_list *ap, t_spec *spec, int *len);
int				print_hex(va_list *ap, t_spec *spec, int *len);
int				print_hex_upper(va_list *ap, t_spec *spec, int *len);
int				print_float(va_list *ap, t_spec *spec, int *len);
int				print_efloat(va_list *ap, t_spec *spec, int *len);
int				print_char(va_list *ap, t_spec *spec, int *len);
int				print_string(va_list *ap, t_spec *spec, int *len);
int				print_pointer(va_list *ap, t_spec *spec, int *len);
int				print_binary(va_list *ap, t_spec *spec, int *len);

char			*pf_uitoa_base(unsigned long long num, int base, int len);

#endif
