/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_char_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <trecomps@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 14:41:23 by trecomps          #+#    #+#             */
/*   Updated: 2016/02/08 16:56:31 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t				size_char_base(char n, int base)
{
	size_t			len;
	unsigned char	tmp;

	len = (n < 0);
	tmp = (n < 0) ? -n : n;
	while (tmp >= (unsigned int)base)
	{
		len++;
		tmp = tmp / base;
	}
	return (len + 1);
}

size_t				size_uchar_base(unsigned char n, int base)
{
	size_t			len;

	len = 0;
	while (n >= base)
	{
		len++;
		n = n / base;
	}
	return (len + 1);
}
