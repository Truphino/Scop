/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <trecomps@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 11:56:32 by trecomps          #+#    #+#             */
/*   Updated: 2016/01/11 12:08:53 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putnbr_base(int n, int base)
{
	char	*c;

	c = "0123456789abcdef";
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		if (base == 10)
			ft_putchar('-');
		n = -n;
	}
	if (n < base)
		ft_putchar(c[n]);
	if (n >= base)
	{
		ft_putnbr_base(n / base, base);
		ft_putchar(c[n % 10]);
	}
}
