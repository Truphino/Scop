/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_toa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <trecomps@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 21:08:37 by trecomps          #+#    #+#             */
/*   Updated: 2016/02/08 16:59:27 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*char_toa_base(char n, int base)
{
	size_t			len;
	char			*res;
	char			*c;
	unsigned char	tmp;

	c = "0123456789abcdef";
	len = size_char_base(n, base);
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
