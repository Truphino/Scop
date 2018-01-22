/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <trecomps@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:13:39 by trecomps          #+#    #+#             */
/*   Updated: 2016/02/06 20:26:24 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putwchar(wchar_t c)
{
	if (c <= 127)
		ft_putchar(c);
	else if (c <= 2047)
	{
		ft_putchar(((c >> 6) & 31) | 192);
		ft_putchar((c & 63) | 128);
	}
	else if (c <= 65535)
	{
		ft_putchar(((c >> 12) & 15) | 224);
		ft_putchar(((c >> 6) & 63) | 128);
		ft_putchar((c & 63) | 128);
	}
	else if (c <= 2097151)
	{
		ft_putchar(((c >> 18) & 7) | 240);
		ft_putchar(((c >> 12) & 63) | 128);
		ft_putchar(((c >> 6) & 63) | 128);
		ft_putchar((c & 63) | 128);
	}
}
