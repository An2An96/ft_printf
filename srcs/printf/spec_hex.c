/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:25:02 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/26 16:58:25 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_strupper(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	}
}

// static char	*ft_strfromchr(char c, size_t n)
// {
// 	char	*res;

// 	if ((res = (char *)malloc(sizeof(char) * (n + 1))) == NULL)
// 		return (NULL);
// 	res[n] = '\0';
// 	res[0] = c;
// 	while (--n)
// 	{
// 		res[n] = c;
// 	}
// 	return (res);
// }

static char	*ft_getstr(void *value, t_spec spec)
{
	char	*res;
	char	*buf;
	int		len;
	char	c;
	int		ox;

	c = ' ';
	ox = 0;
	res = NULL;
	if (spec.accuracy == 0)
	{
		if (spec.flags & FLAG_MINUS)
			ft_str_fixlen(&res, c, spec.width, ' ');
		else if (spec.flags & FLAG_ZERO)
			ft_str_fixlen(&res, c, spec.width, '0');
		if (res == NULL)
			res = ft_strdup("");
		return (res);
	}
	if (spec.size == SIZE_l)
		res = ft_uitoa_base(*((unsigned long*)value), 16);
	else if (spec.size == SIZE_ll)
		res = ft_uitoa_base(*((unsigned long long*)value), 16);
	else
		res = ft_uitoa_base(*((unsigned int*)value), 16);
	if ((spec.flags & FLAG_OCTOP) && (*((long long*)value) != 0) )
		ox = 2;
	len = ft_strlen(res) + ox;
	if (spec.width > 1 && spec.width - len > 0)
	{
		if (spec.flags & FLAG_MINUS)
		{
			ft_str_fixlen(&res, c, spec.width - ox, 1);
		}
		else
		{
			if (spec.flags & FLAG_ZERO)
				c = '0';
			else if (ox != 0)
			{
				buf = res;
				res = ft_strjoin("0x", res);
				free(buf);
				ox = 0;
			}
			ft_str_fixlen(&res, c, spec.width - ox, 0);
		}
	}
	if (ox != 0)
	{
		buf = res;
		res = ft_strjoin("0x", res);
		free(buf);
	}
	return (res);
}

int			print_hex(void *value, t_spec spec)
{
	char	*res;

	res = ft_getstr(value, spec);
	ft_putstr(res);
	return (ft_strlen(res));
}

int			print_hex_upper(void *value, t_spec spec)
{
	char	*res;

	res = ft_getstr(value, spec);
	ft_strupper(res);
	ft_putstr(res);
	return (ft_strlen(res));
}
