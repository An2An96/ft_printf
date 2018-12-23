/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:08:21 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/23 20:10:34 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "dispatcher.h"

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
						value = va_arg(ap, ssize_t);
						if (g_dispatcher[i].arg_type == TYPE_PTR)
							ptr = (void*)value;
						else
							ptr = &value;
						if (format - start > 1)
						{
							body = ft_strnew(format - start - 1);
							ft_strncpy(body, (start + 1), (format - start - 1));
						}
						formating(body, ptr, g_dispatcher[i].func);
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
