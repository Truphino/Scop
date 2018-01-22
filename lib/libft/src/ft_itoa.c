/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:13:43 by trecomps          #+#    #+#             */
/*   Updated: 2016/01/11 17:18:30 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_itoa(int n)
{
	size_t	len;
	char	*res;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = size_int(n);
	res = ft_strnew(len);
	if (!res)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		res[0] = '-';
	}
	while (len > 0)
	{
		res[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	if (res[len] != '-')
		res[len] = n % 10 + '0';
	return (res);
}
