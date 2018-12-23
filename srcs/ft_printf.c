/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:08:21 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/23 17:09:43 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dispatcher.h"

void	print_number(void *value, char flags, int width, int accuracy, char size)
{
	printf("flag [-]: %s\n", flags & FLAG_MINUS ? "yes" : "no");
	printf("flag [+]: %s\n", flags & FLAG_PLUS ? "yes" : "no");
	printf("flag [ ]: %s\n", flags & FLAG_SPACE ? "yes" : "no");
	printf("flag [#]: %s\n", flags & FLAG_OCTOP ? "yes" : "no");
	printf("flag [0]: %s\n", flags & FLAG_ZERO ? "yes" : "no");
	printf("width: %d\n", width);
	printf("accuracy: %d\n", accuracy);
	printf("size: %d\n", size);
	ft_putnbr(*((int*)value));
}

void	print_hex(void *value, char flags, int width, int accuracy, char size)
{
	char *res;

	res = NULL;
	if (size == SIZE_l)
	{
		res = ft_itoa_base(*((long*)value), 16);
	}
	else
	{
		res = ft_itoa_base(*((int*)value), 16);
	}
	ft_putstr(res);
}

// void	print_char(void *value, char flags, int width, int accuracy, char size)
// {
// 	/* 
// 		+ не обрабатывать флаги кроме FLAG_MINUS
// 		+ не обрабатывать accuracy
// 		- не обрабатывать размер кроме l
// 	*/
// 	char *res;

// 	if (flags & FLAG_MINUS)
// 	{
// 		width = width <= 0 ? 1 : width;
// 		res = ft_strnew(width);
// 		if (res)
// 		{
// 			res[0] = *((char*)value);
// 			ft_memset(res + 1, ' ', width - 1);
// 			ft_putstr(res);
// 		}
// 	}
// 	else
// 		ft_putchar(*((char*)value));
// }

void	print_string(void *value, char flags, int width, int accuracy, char size)
{
	ft_putstr((char*)value);
}

void	print_pointer(void *value, char flags, int width, int accuracy, char size)
{
	char *res = ft_itoa_base((long long)value, 16);
	if (res)
	{
		ft_putstr("0x");
		ft_putstr(ft_strlower(res));
	}
}

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
					if (format[i] == dispatcher[j].type_specifier)
					{
						if (dispatcher[j].arg_type == TYPE_INT
							|| dispatcher[j].arg_type == TYPE_CHAR)
						{
							value = va_arg(ap, ssize_t);
							ptr = (void*)(&value);
						}
						else if (dispatcher[j].arg_type == TYPE_PTR)
						{
							ptr = va_arg(ap, void*);
						}
						if (i - in_formatter > 1)
						{
							body = ft_strnew(i - in_formatter - 1);
							ft_strncpy(body, (format + in_formatter + 1), (i - in_formatter - 1));
						}
						formating(body, ptr, dispatcher[j].func);
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
