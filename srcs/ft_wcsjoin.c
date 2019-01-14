/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:56:19 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/14 20:16:54 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "inside.h"

size_t	ft_wcslen(const wchar_t *s)
{
	size_t i;

	i = 0;
	if (s)
		while (s[i] != '\0')
			i++;
	return (i);
}

wchar_t	*ft_wcsnew(size_t size)
{
	return (wchar_t*)ft_memalloc((size + 1) * sizeof(wchar_t));
}

wchar_t	*ft_wcscpy(wchar_t *dest, const wchar_t *src)
{
	unsigned int i;

	i = 0;
	if (src)
	{
		while (src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = '\0';
	return (dest);
}

wchar_t	*ft_wcsjoin(wchar_t const *s1, wchar_t const *s2)
{
	wchar_t	*res;
	size_t	s1_len;

	res = NULL;
	s1_len = ft_wcslen(s1);
	res = ft_wcsnew(s1_len + ft_wcslen(s2));
	if (res)
	{
		ft_wcscpy(res, s1);
		ft_wcscpy(res + s1_len, s2);
	}
	return (res);
}

wchar_t	*ft_wcsdup(const wchar_t *src)
{
	int		i;
	wchar_t	*dest;

	dest = NULL;
	if (src)
	{
		dest = (wchar_t*)malloc((ft_wcslen(src) + 1) * sizeof(wchar_t));
		if (dest)
		{
			i = 0;
			while (src[i] != '\0')
			{
				dest[i] = src[i];
				i++;
			}
			dest[i] = '\0';
		}
	}
	return (dest);
}

wchar_t	*ft_wcscut(wchar_t const *s, size_t len)
{
	unsigned int	i;
	wchar_t			*res;
	size_t			src_len;

	res = NULL;
	if (s)
	{
		src_len = ft_wcslen(s);
		len = len > src_len ? src_len : len;
		res = ft_wcsnew(len);
		if (res)
		{
			i = 0;
			while (i < len)
			{
				res[i] = s[i];
				i++;
			}
		}
	}
	return (res);
}

int	ft_wcsfixlen(wchar_t **str, wchar_t ch, int width, int side)
{
	int		len;
	wchar_t	*new;

	len = ft_wcslen(*str);
	if (len >= width)
		return (len);
	new = ft_wcsnew(width);
	if (new)
	{
		if (side)
		{
			ft_memmove(new, *str, len);
			ft_memset(new + len, ch, width - len);
		}
		else
		{
			ft_memmove(new + (width - len), *str, len);
			ft_memset(new, ch, width - len);
		}
		free(*str);
		*str = new;
	}
	return (width);
}

void	ft_putwstr(wchar_t const *s)
{
	if (s)
	{
		while (*s)
		{
			ft_putchar(*s);
			s++;
		}
	}
}
