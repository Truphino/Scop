/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ullong_toa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <trecomps@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 12:53:02 by trecomps          #+#    #+#             */
/*   Updated: 2016/02/08 17:00:26 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ullong_toa_base(unsigned long long n, int base)
{
	size_t		len;
	char		*res;
	char		*c;

	c = "0123456789abcdef";
	len = size_ullong_base(n, base);
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
