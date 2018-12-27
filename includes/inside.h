/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inside.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:09:16 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/27 22:06:47 by rschuppe         ###   ########.fr       */
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

enum			e_types
{
	TYPE_NONE,
	TYPE_INT,
	TYPE_PTR,
	TYPE_DOUBLE,
	TYPE_UNSIGNED
};

typedef enum	e_sp_size
{
	SIZE_NONE,
	SIZE_l,
	SIZE_hh,
	SIZE_h,
	SIZE_ll,
	SIZE_z,
	SIZE_L
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
	int			(*func)(void*, t_spec*, int*);
	char		arg_type;
}				t_formatter;

int				find_specifier(const char ch);
void			parse_spec_body(char *body, t_spec *spec);
int				is_spec_body_char(char ch);
char			get_flags(char **body);
int				get_accuracy(char *body);
char			get_size(char *body);

void			double_handler(t_spec *spec, t_value_types *value, va_list *ap);
void			int_handler(t_spec *spec, t_value_types *value, va_list *ap);
void			unsigned_handler(
	t_spec *spec, t_value_types *value, va_list *ap);

int				write_len(void *value, t_spec *spec, int *len);
int				print_percent(void *value, t_spec *spec, int *len);
int				print_number(void *value, t_spec *spec, int *len);
int				print_octal(void *value, t_spec *spec, int *len);
int				print_unsigned(void *value, t_spec *spec, int *len);
int				print_hex(void *value, t_spec *spec, int *len);
int				print_hex_upper(void *value, t_spec *spec, int *len);
int				print_float(void *value, t_spec *spec, int *len);
int				print_char(void *value, t_spec *spec, int *len);
int				print_string(void *value, t_spec *spec, int *len);
int				print_pointer(void *value, t_spec *spec, int *len);
int				print_binary(void *value, t_spec *spec, int *len);

char			*pf_uitoa_base(unsigned long long num, int base, int len);


#endif
