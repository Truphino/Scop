/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llong_toa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <trecomps@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 21:10:36 by trecomps          #+#    #+#             */
/*   Updated: 2016/02/08 16:59:38 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*llong_toa_base(long long n, int base)
{
	size_t				len;
	char				*res;
	char				*c;
	unsigned long long	tmp;

	c = "0123456789abcdef";
	len = size_llong_base(n, base);
	if ((res = ft_strnew(len)) == NULL)
		return (NULL);
	len--;
	tmp = (n < 0) ? -n : n;
	if (n < 0)
		res[0] = '-';
	while (len > 0)
	{
		res[len] = c[tmp % base];
		tmp = tmp / base;
		len--;
	}
	if (res[len] != '-')
		res[len] = c[tmp % base];
	return (res);
}
