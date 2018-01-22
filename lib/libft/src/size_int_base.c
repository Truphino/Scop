/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_int_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <trecomps@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:10:35 by trecomps          #+#    #+#             */
/*   Updated: 2016/02/08 16:56:47 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t				size_int_base(int n, int base)
{
	size_t			len;
	unsigned int	tmp;

	len = (n < 0);
	tmp = (n < 0) ? -n : n;
	while (tmp >= (unsigned)base)
	{
		len++;
		tmp = tmp / base;
	}
	return (len + 1);
}

size_t				size_uint_base(unsigned int n, int base)
{
	size_t			len;

	len = 0;
	while (n >= (unsigned int)base)
	{
		len++;
		n = n / (unsigned int)base;
	}
	return (len + 1);
}
