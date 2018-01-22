/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:13:43 by trecomps          #+#    #+#             */
/*   Updated: 2016/02/08 17:00:08 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*uchar_toa_base(unsigned char n, int base)
{
	size_t		len;
	char		*res;
	char		*c;

	c = "0123456789abcdef";
	len = size_uchar_base(n, base);
	if ((res = ft_strnew(len)) == NULL)
		return (NULL);
	len--;
	while (len > 0)
	{
		res[len] = c[n % base];
		n = n / base;
		len--;
	}
	if (res[len] != '-')
		res[len] = c[n % base];
	return (res);
}
