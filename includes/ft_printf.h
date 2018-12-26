/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:09:16 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/26 15:01:41 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include "libft.h"

# define FLAG_MINUS		1
# define FLAG_PLUS		2
# define FLAG_SPACE		4
# define FLAG_OCTOP		8
# define FLAG_ZERO		16

enum			e_types
{
	TYPE_NONE,
	TYPE_INT,
	TYPE_CHAR,
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
	SIZE_L
}				t_sp_size;

typedef struct	s_value_types {
	void		*p_value;
	long long	l_value;
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
	int			(*func)(void*, t_spec);
	char		arg_type;
}				t_formatter;

int				ft_printf(const char *format, ...);
int				find_specifier(const char ch, const t_formatter *dispatcher);
void			parse_spec_body(char *body, t_spec *spec);
char			get_flags(char **body);
int				get_accuracy(char *body);
char			get_size(char *body);

int				print_percent(void *value, t_spec spec);
int				print_number(void *value, t_spec spec);
int				print_octal(void *value, t_spec spec);
int				print_unsigned(void *value, t_spec spec);
int				print_hex(void *value, t_spec spec);
int				print_hex_upper(void *value, t_spec spec);
int				print_float(void *value, t_spec spec);
int				print_char(void *value, t_spec spec);
int				print_string(void *value, t_spec spec);
int				print_pointer(void *value, t_spec spec);

void			ft_strdel(char **as);
char			*ft_strlower(char *str);
char			*ft_strnew(size_t size);
char			*ft_strsub(char const *s, unsigned int start, size_t len);

char			*ft_uitoa_base(size_t num, int base);

#endif
