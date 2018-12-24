/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:08:21 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/24 19:29:38 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "dispatcher.h"

static char		get_flags(char **body)
{
	char flags;

	flags = 0;
	if (body && *body)
	{
		while (**body)
		{
			if (**body == '-')
				flags |= FLAG_MINUS;
			else if (**body == '+')
				flags |= FLAG_PLUS;
			else if (**body == ' ')
				flags |= FLAG_SPACE;
			else if (**body == '#')
				flags |= FLAG_OCTOP;
			else if (**body == '0')
				flags |= FLAG_ZERO;
			else
				break ;
			(*body)++;
		}
	}
	return (flags);
}

static int		get_accuracy(char *body)
{
	char *start;

	if ((start = ft_strchr(body, '.')))
		return (ft_atoi(start + 1));
	return (0);
}

static char		get_size(char *body)
{
	t_sp_size size;

	size = SIZE_NONE;
	while (*body)
	{
		if (body[0] == 'L')
		{
			size = SIZE_L;
			break ;
		}
		else if (body[0] == 'l')
		{
			if (body[1] == 'l')
				size = SIZE_ll;
			else
				size = SIZE_l;
			break ;
		}
		else if (body[0] == 'h')
		{
			if (body[1] == 'h')
				size = SIZE_hh;
			else
				size = SIZE_h;
			break ;
		}
		body++;
	}
	return (size);
}

// static void		formating(char *body, void *value, void (*f)(void *, char, int, int, char))
// {
// 	char	flags;
// 	int		width;
// 	int		accuracy;
// 	char	size;

// 	flags = 0;
// 	width = 0;
// 	accuracy = 0;
// 	if (body)
// 	{
// 		flags = get_flags(&body);
// 		width = ft_atoi(body);
// 		accuracy = get_accuracy(body);
// 		size = get_size(body);
// 	}
// 	f(value, flags, width, accuracy, size);
// }

void	parse_spec_body(char *body, t_spec *spec)
{
	if (body)
	{
		spec->flags = get_flags(&body);
		spec->width = ft_atoi(body);
		spec->accuracy = get_accuracy(body);
		spec->size = get_size(body);
	}
}

int				ft_printf(const char *format, ...)
{
	va_list	ap;
	t_value_types	value;
	t_spec			spec;
	void*	ptr;
	char	*body;
	int		i;
	char	*start;

	va_start(ap, format);
 
	body = NULL;
	start = NULL;
	while (*format)
	{
		if (*format == '%')
		{	
			if (start)
			{
				ft_putchar('%');
				start = NULL;
			}
			else
				start = (char*)format;
		}
		else
		{
			if (start)
			{
				i = -1;
				while (g_dispatcher[++i].type_specifier)
				{
					if (*format == g_dispatcher[i].type_specifier)
					{
						if (format - start > 1)
						{
							body = ft_strnew(format - start - 1);
							ft_strncpy(body, (start + 1), (format - start - 1));
						}
						parse_spec_body(body, &spec);

						if (g_dispatcher[i].arg_type == TYPE_PTR)
						{
							value.p_value = va_arg(ap, ssize_t);
							ptr = (void*)value.p_value;
						}
						else if (g_dispatcher[i].arg_type == TYPE_INT)
						{
							value.i_value = va_arg(ap, int);
							ptr = (void*)(&value.i_value);
						}
						else if (g_dispatcher[i].arg_type == TYPE_FLOAT)
						{
							if (spec.size == SIZE_L)
							{
								value.ld_value = va_arg(ap, long double);
								ptr = (void*)(&value.ld_value);
							}
							else
							{
								value.d_value = va_arg(ap, double);
								ptr = (void*)(&value.d_value);
							}
						}
						// if (format - start > 1)
						// {
						// 	body = ft_strnew(format - start - 1);
						// 	ft_strncpy(body, (start + 1), (format - start - 1));
						// }
						// formating(body, ptr, g_dispatcher[i].func);
						g_dispatcher[i].func(ptr, spec);
						ft_strdel(&body);
						start = NULL;
						break ;
					}
				}
			}
			else
				ft_putchar(*format);
		}
		format++;
	}
	va_end(ap);
	return (1);
}
