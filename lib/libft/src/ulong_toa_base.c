/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulong_toa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <trecomps@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 12:50:11 by trecomps          #+#    #+#             */
/*   Updated: 2016/02/08 17:00:35 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ulong_toa_base(unsigned long n, int base)
{
	size_t		len;
	char		*res;
	char		*c;

	c = "0123456789abcdef";
	len = size_ulong_base(n, base);
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
