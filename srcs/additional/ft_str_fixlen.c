/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_fixlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 14:36:48 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/26 15:17:52 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_fixlen(char **str, char ch, size_t width, int side)
{
	size_t	len;
	char	*new;

	len = ft_strlen(*str);
	if (len >= width)
		return (len);
	new = ft_strnew(width);
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
