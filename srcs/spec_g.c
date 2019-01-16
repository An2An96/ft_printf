/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_g.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 16:29:18 by anorjen           #+#    #+#             */
/*   Updated: 2019/01/16 17:34:50 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inside.h"

static char	*ft_gg(va_list *ap, t_spec *spec)
{
	char	*res1;
	char	*res2;
	int		i;

	res1 = ft_floattostr(ap, spec);
	res2 = ft_efloattostr(ap, spec);
	i = ft_strlen(res1) - 1;
	while (res1[i] == '0' || res1[i] == '.')
		i--;
	res1[i + 1] = '\0';
	return (ft_strlen(res1) < ft_strlen(res2) ? res1 : res2);
}

static char	*ft_gfloattostr(va_list *ap, t_spec *spec)
{
	char	*res;

	spec->accuracy = spec->accuracy == -1 ? 6 : spec->accuracy;
	if (spec->size == SIZE_L)
		res = ft_gg(ap, spec);
	else
		res = ft_gg(ap, spec);
	return (res);
}

int			print_gfloat(va_list *ap, t_spec *spec, int *len)
{
	char	*res;
	char	c;
	int		tmp;
	int		side;

	side = 0;
	c = (!IS_FLAG(FLAG_MINUS) && IS_FLAG(FLAG_ZERO) ? '0' : ' ');
	if ((res = ft_gfloattostr(ap, spec)) == NULL)
		return (0);
	if (spec->width - ft_strlen(res) > 0)
		side = (IS_FLAG(FLAG_MINUS) ? 1 : 0);
	tmp = ft_str_fixlen(&res, c, spec->width, side);
	if (IS_FLAG(FLAG_MINUS) && IS_FLAG(FLAG_SPACE))
	{
		ft_putchar(' ');
		write(1, res, tmp++);
	}
	else
		write(1, res, tmp);
	free(res);
	*len += tmp;
	return (1);
}

int			print_gfloat_upper(va_list *ap, t_spec *spec, int *len)
{
	char	*res;
	char	c;
	int		tmp;
	int		side;

	side = 0;
	c = (!IS_FLAG(FLAG_MINUS) && IS_FLAG(FLAG_ZERO) ? '0' : ' ');
	if ((res = ft_gfloattostr(ap, spec)) == NULL)
		return (0);
	if (spec->width - ft_strlen(res) > 0)
		side = (IS_FLAG(FLAG_MINUS) ? 1 : 0);
	tmp = ft_str_fixlen(&res, c, spec->width, side);
	if (IS_FLAG(FLAG_MINUS) && IS_FLAG(FLAG_SPACE))
	{
		ft_putchar(' ');
		write(1, ft_strupper(res), tmp++);
	}
	else
		write(1, ft_strupper(res), tmp);
	free(res);
	*len += tmp;
	return (1);
}


// int			print_gfloat(va_list *ap, t_spec *spec, int *len)
// {
// 	char	*res;
// 	char	*str;
// 	char	c;
// 	int		side;
// 	int		tmp;

// 	side = 0;
// 	c = (!IS_FLAG(FLAG_MINUS) && IS_FLAG(FLAG_ZERO) ? '0' : ' ');
// 	if ((res = ft_gfloattostr(ap, spec)) == NULL)
// 		return (0);
// 	if (spec->width - ft_strlen(res) > 0)
// 		side = (IS_FLAG(FLAG_MINUS) ? 1 : 0);
// 	tmp = ft_str_fixlen(&res, c, spec->width - 2, side) + 2;
// 	str = ft_strjoin("0x", res);
// 	free(res);
// 	if (IS_FLAG(FLAG_MINUS) && IS_FLAG(FLAG_SPACE))
// 	{
// 		ft_putchar(' ');
// 		write(1, str, tmp++);
// 	}
// 	else
// 		write(1, str, tmp);
// 	free(str);
// 	*len += tmp;
// 	return (1);
// }

// int			print_gfloat_upper(va_list *ap, t_spec *spec, int *len)
// {
// 	char	*res;
// 	char	*str;
// 	char	c;
// 	int		side;
// 	int		tmp;

// 	side = 0;
// 	c = (!IS_FLAG(FLAG_MINUS) && IS_FLAG(FLAG_ZERO) ? '0' : ' ');
// 	if ((res = ft_gfloattostr(ap, spec)) == NULL)
// 		return (0);
// 	if (spec->width - ft_strlen(res) > 0)
// 		side = (IS_FLAG(FLAG_MINUS) ? 1 : 0);
// 	tmp = ft_str_fixlen(&res, c, spec->width - 2, side) + 2;
// 	str = ft_strjoin("0x", res);
// 	free(res);
// 	if (IS_FLAG(FLAG_MINUS) && IS_FLAG(FLAG_SPACE))
// 	{
// 		ft_putchar(' ');
// 		write(1, ft_strupper(str), tmp++);
// 	}
// 	else
// 		write(1, ft_strupper(str), tmp);
// 	free(str);
// 	*len += tmp;
// 	return (1);
// }