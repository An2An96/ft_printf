/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:58:33 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/14 19:31:55 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(wchar_t c)
{
	char ch;

	if (c < 128)
	{
		ch = c;
		write(1, &ch, 1);
	}
	else if (c < 2048)
	{
		ch = (c >> 6) | 0xC0;
		write(1, &ch, 1);
		ch = (c & 63) | 0x80;
		write(1, &ch, 1);
	}
    else if (c < 1 << 16)
	{
		ch = (c >> 12) | 0xE0;
		write(1, &ch, 1);
		ch = (c >> 6 & 63) | 0x80;
		write(1, &ch, 1);
		ch = (c & 63) | 0x80;
		write(1, &ch, 1);
	}
    else if(c < 1 << 21)
	{
		ch = (c >> 18) | 0xF0;
		write(1, &ch, 1);
		ch = (c >> 12 & 63) | 0x80;
		write(1, &ch, 1);
		ch = (c >> 6 & 63) | 0x80;
		write(1, &ch, 1);
		ch = (c & 63) | 0x80;
		write(1, &ch, 1);
	}
}
