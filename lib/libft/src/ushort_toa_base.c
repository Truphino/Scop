/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ushort_toa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <trecomps@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 12:45:19 by trecomps          #+#    #+#             */
/*   Updated: 2016/02/08 17:00:47 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ushort_toa_base(unsigned short int n, int base)
{
	size_t		len;
	char		*res;
	char		*c;

	c = "0123456789abcdef";
	len = size_ushort_base(n, base);
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
