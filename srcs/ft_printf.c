/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:08:21 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/23 17:39:50 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		get_flags(char **body)
{
	char flags;

	flags = 0;
	if (body)
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

static void		formating(char *body, void *value, void (*f)(void *, char, int, int, char))
{
	char	flags;
	int		width;
	int		accuracy;
	char	size;

	flags = 0;
	width = 0;
	accuracy = 0;
	if (body)
	{
		flags = get_flags(&body);
		width = ft_atoi(body);
		accuracy = get_accuracy(body);
		size = get_size(body);
	}
	f(value, flags, width, accuracy, size);
}

int				ft_printf(const char *format, ...)
{
	
	va_list	ap;
	ssize_t	value;
	void*	ptr;
	char	*body;
	int		i;
	int		j;
	int		in_formatter;

	va_start(ap, format);
 
	i = 0;
	in_formatter = -1;
	body = NULL;
	while (format[i])
	{
		if (format[i] == '%')
		{	
			if (in_formatter == -1)
				in_formatter = i;
			else
			{
				ft_putchar('%');
				in_formatter = -1;
			}
		}
		else
		{
			if (in_formatter != -1)
			{
				j = -1;
				while (++j < 5)
				{
					if (format[i] == g_dispatcher[j].type_specifier)
					{
						if (g_dispatcher[j].arg_type == TYPE_INT
							|| g_dispatcher[j].arg_type == TYPE_CHAR)
						{
							value = va_arg(ap, ssize_t);
							ptr = (void*)(&value);
						}
						else if (g_dispatcher[j].arg_type == TYPE_PTR)
						{
							ptr = va_arg(ap, void*);
						}
						if (i - in_formatter > 1)
						{
							body = ft_strnew(i - in_formatter - 1);
							ft_strncpy(body, (format + in_formatter + 1), (i - in_formatter - 1));
						}
						formating(body, ptr, g_dispatcher[j].func);
						ft_strdel(&body);
						in_formatter = -1;
						break ;
					}
				}
			}
			else
			{
				ft_putchar(format[i]);
			}
		}
		i++;
	}

	va_end(ap);
	return (1);
}
