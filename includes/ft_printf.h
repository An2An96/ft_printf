/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:09:16 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/23 14:52:56 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>		//	dev
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

// typedef enum	e_flags
// {
// 	FLAG_NONE	= 0,
// 	FLAG_MINUS	= 1,
// 	FLAG_PLUS	= 2,
// 	FLAG_SPACE	= 4,
// 	FLAG_OCTOP	= 8,
// 	FLAG_ZERO	= 16
// }				t_flags;

typedef enum	e_sp_size
{
	SIZE_NONE,
	SIZE_l,
	SIZE_hh,
	SIZE_h,
	SIZE_ll,
	SIZE_L
}				t_sp_size;

int		ft_printf(const char *format, ...);

#endif
