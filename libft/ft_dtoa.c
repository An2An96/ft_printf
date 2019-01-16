/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 13:19:27 by anorjen           #+#    #+#             */
/*   Updated: 2019/01/16 18:59:28 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char		*ft_dtoa(long double num, int acc)
// {
// 	ssize_t		nbr;
// 	char		*fraction;
// 	char		*buf;
// 	char		*res;
// 	ssize_t		eps;

// 	eps = (ssize_t)ft_pow(10, acc);
// 	nbr = (ssize_t)(num < 0 ? -1 : 1) * ((ABS(num) + 0.5 / eps) * eps);
// 	if (acc == 0)
// 		return (ft_stoa(nbr / eps));
// 	fraction = ft_stoa(ABS(nbr) % eps);
// 	if (ft_strlen(fraction) < (size_t)acc)
// 		ft_str_fixlen(&fraction, '0', acc, 0);
// 	buf = ft_strjoin(ft_stoa(nbr / eps), ".");
// 	res = ft_strjoin(buf, fraction);
// 	free(buf);
// 	return (res);
// }

char	*ft_dtoa(long double n, int tolerance)
{
  char s[40], t, *temp;
  long double num;
  int i, j;
  i = tolerance;
  j = 0;
  ssize_t	eps;
  //num = n;
  eps = (ssize_t)ft_pow(10, tolerance);
  num = (n < 0 ? -1 : 1) * (ABS(n) + 0.5 / eps);
  if (num < 0) // определяем знак числа
  {
    num = -num;
    s[j] = '-';
    j++;
  }
  do { // преобразуем к нормированной форме (если не меньше 1)
    num = num / 10;
    i++;
  } while ((int)num > 0);
  num = num * 10;
  while (i > 0)
  {
    t = (int)num; // выделяем цифру, соответствующую целой части
    s[j] = t | 0x30;
    i--;
	j++;
    if (i == tolerance) { // определяем положение десятичного разделителя
      s[j] = '.';
      j++;
    }
    num = num - (double)t; // вычитаем из числа целую часть
    num = num * 10; // переходим к следующему разряду
  }
  s[j] = '\0';
  j++;
  temp = ft_strnew(j); // выделяем память под возвращаемую строку
  for (i = 0; i < j; i++) // формируем возвращаемую строку
    temp[i] = s[i];
  return(temp);
}
