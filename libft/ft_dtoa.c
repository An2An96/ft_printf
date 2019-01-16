/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 13:19:27 by anorjen           #+#    #+#             */
/*   Updated: 2019/01/16 20:18:04 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_dtoa(long double num, int acc)
{
	ssize_t		nbr;
	char		*fraction;
	char		*buf;
	char		*res;
	ssize_t		eps;

	eps = (ssize_t)ft_pow(10, acc);
	nbr = (ssize_t)(num < 0 ? -1 : 1) * ((ABS(num) + 0.5 / eps) * eps);
	if (acc == 0)
		return (ft_stoa(nbr / eps));
	fraction = ft_stoa(ABS(nbr) % eps);
	if (ft_strlen(fraction) < (size_t)acc)
		ft_str_fixlen(&fraction, '0', acc, 0);
	buf = ft_strjoin(ft_stoa(nbr / eps), ".");
	res = ft_strjoin(buf, fraction);
	free(buf);
	return (res);
}

// char	*ft_dtoa(long double n, int acc)
// {
// 	char		s[40];
// 	char		t;
// 	long double	num;
// 	int 		i;
// 	int			j;

// 	i = acc;
// 	j = 0;
// 	num = (n < 0 ? -1 : 1) * (ABS(n) + 0.5 / (ssize_t)ft_pow(10, acc));
// 	if (num < 0)
// 	{
// 		num = -num;
// 		s[j] = '-';
// 		j++;
// 	}
// 	do {
// 		num = num / 10;
// 		i++;
// 	} while ((int)num > 0);
// 	num = num * 10;
// 	while (i > 0)
// 	{
// 		t = (int)num;
// 		s[j] = t | 0x30;
// 		i--;
// 		j++;
// 		if (i == acc)
// 		{
// 			s[j] = '.';
// 			j++;
// 		}
// 		num = num - (double)t;
// 		num = num * 10;
// 	}
// 	s[j] = '\0';
// 	return (ft_strdup(s));
// }




// static int			count_big_f(long double f)
// {
// 	int count;

// 	count = 0;
// 	while (f > 1)
// 	{
// 		count++;
// 		f /= 10;
// 	}
// 	return (count ? count : 1);
// }

// static long double	pf_atof_helper(char *s)
// {
// 	long double f;

// 	f = 0;
// 	while (*s)
// 	{
// 		f *= 10;
// 		f += (long double)(*s - '0');
// 		++s;
// 	}
// 	return (f);
// }

// static char			*big_f(long double f)
// {
// 	char		*s;
// 	char		*ptr;
// 	int			count;
// 	int			i;
// 	long double	temp;

// 	count = count_big_f(f);
// 	if (!(s = (char*)ft_memalloc(count + 1)))
// 		return (NULL);
// 	ptr = s;
// 	while (count)
// 	{
// 		i = count - 1;
// 		temp = f;
// 		while (i--)
// 			temp /= 10;
// 		*ptr++ = (int)temp + '0';
// 		temp = (int)temp;
// 		while (++i < count - 1)
// 			temp *= 10;
// 		f -= temp;
// 		--count;
// 	}
// 	return (s);
// }

// static char			*little_f(long double f, int p, char *big_f)
// {
// 	char	*s;
// 	int		i;

// 	i = 0;
// 	f = f < 0 ? -f : f;
// 	f -= pf_atof_helper(big_f);
// 	if (!(s = (char*)ft_memalloc(p + 1)))
// 		return (NULL);
// 	while (i < p)
// 	{
// 		f *= 10;
// 		s[i++] = (f > 0) ? (int)f + '0' : '0';
// 		f -= (int)f;
// 	}
// 	return (s);
// }

// char				*ft_dtoa(long double n, int acc)
// {
// 	char *a;
// 	char *b;
// 	char *c;
// 	int len;

// 	a = big_f(n);
// 	b = little_f(n, acc, a);

// 	len = ft_strlen(a);
// 	c = ft_strnew(len + ft_strlen(b) + 1);
// 	ft_strcpy(c, a);
// 	c[len] = '.';
// 	ft_strcat(c, b);
// 	free(a);
// 	free(b);
// 	return (c);
// }