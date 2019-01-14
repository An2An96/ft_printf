/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_s_un.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:25:25 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/10 21:25:20 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inside.h"

// static char	*ft_strcut(char const *s, size_t len)
// {
// 	unsigned int	i;
// 	char			*res;
// 	size_t			src_len;

// 	res = NULL;
// 	if (s)
// 	{
// 		src_len = ft_strlen(s);
// 		len = len > src_len ? src_len : len;
// 		res = ft_strnew(len);
// 		if (res)
// 		{
// 			i = 0;
// 			while (i < len)
// 			{
// 				res[i] = s[i];
// 				i++;
// 			}
// 		}
// 	}
// 	return (res);
// }

static int	ft_strlen_un(int *s, int *len_un, int num)
{
	int	len;

	len = 0;
	*len_un = 0;
	if (num > 0)
	{
		while (*s != 0 && num > 0)
		{
			if (*s > 128)
				(*len_un)++;
			len++;
			num--;
			s++;
		}
	}
	else
	{
		while (*s != 0)
		{
			if (*s > 128)
				(*len_un)++;
			len++;
			s++;
		}
	}
	return (len);
}

static unsigned char	*ft_unicode(int *str, size_t size)
{
	int				i;
	int				j;
	unsigned char	*res;
	unsigned char	a[2];

	i = -1;
	j = -1;
	if ((res = (unsigned char *)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	res[size] = 0;
	while (++i < size)
	{
		if (str[i] < 128)
		{
			res[++j] = (char)str[i];
		}
		else
		{
			a[0] = 192 + str[i] / 64;
			a[1] = 128 + str[i] % 64;
			res[++j] = a[0];
			res[++j] = a[1];
		}
	}
	return (res);
}

static unsigned char	*ft_strcut_un(int *s, size_t len)
{
	unsigned int	i;
	unsigned char	*res;
	int				src_len;
	int				src_len_un;

	res = NULL;
	if (s)
	{
		src_len = ft_strlen_un(s, &src_len_un, 0);
		// len = len > src_len ? src_len : len;
		if (len > src_len)
			len = 2 * src_len_un + (src_len - src_len_un);
		else
		{
			src_len = ft_strlen_un(s, &src_len_un, len);
			len = 2 * src_len_un + (src_len - src_len_un);
		}
		//res = ft_strnew(len);
		res = ft_unicode(s, len);
	}
	return (res);
}

int			print_string_un(void *value, t_spec *spec, int *len)
{
	int				tmp;
	unsigned char	*res;
	size_t			size;
	int				strlen;
	int				strlen_un;
	int				i;

	if (!value && !spec->width)
		value = ft_strjoin(value, "(null)");
	// else
	// {
	// 	//value = ft_strdup(value);
	// 	size = ft_strlen(value);
	// 	value = ft_unicode(value, size, &tmp);
	// }
	if (spec->accuracy > 0)
		res = ft_strcut_un(value, spec->accuracy);
	else
	{
		strlen = ft_strlen_un(value, &strlen_un, 0);
		strlen = strlen + strlen_un;
		res = ft_strcut_un(value, strlen);
	}
	if (!res)
		return (0);
	if (CHECK_FLAG(FLAG_MINUS))
		tmp = ft_str_fixlen(&res, ' ', spec->width, 1);
	else
		tmp = ft_str_fixlen(&res,
			CHECK_FLAG(FLAG_ZERO) ? '0' : ' ', spec->width, 0);
	//ft_putstr(res);
	i = -1;
	while (res[++i])
		write(1, &res[i], 1);
	*len += (spec->width > (strlen - strlen_un) ? spec->width : (strlen - strlen_un));
	free(res);
	return (1);
}
