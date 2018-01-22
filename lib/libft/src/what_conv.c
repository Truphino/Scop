/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <trecomps@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 12:56:05 by trecomps          #+#    #+#             */
/*   Updated: 2016/02/08 16:32:49 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*what_uconv(va_list arg, t_data *data, int base)
{
	if (data->len_mod == 1)
		return (uchar_toa_base((unsigned char)va_arg(arg, unsigned int), base));
	if (data->len_mod == 2)
		return (ullong_toa_base(va_arg(arg, unsigned long long), base));
	if (data->len_mod == 4)
		return (ushort_toa_base((unsigned short)va_arg(arg, unsigned), base));
	if (data->len_mod == 8)
		return (ulong_toa_base(va_arg(arg, unsigned long), base));
	if (data->len_mod == 16 || data->len_mod == 32)
		return (ullong_toa_base(va_arg(arg, unsigned long long), base));
	return (uint_toa_base(va_arg(arg, unsigned int), base));
}

char		*what_conv(va_list arg, t_data *data, int base)
{
	if (data->len_mod == 1)
		return (char_toa_base((char)va_arg(arg, int), base));
	if (data->len_mod == 2)
		return (llong_toa_base(va_arg(arg, long long), base));
	if (data->len_mod == 4)
		return (short_toa_base((short)va_arg(arg, int), base));
	if (data->len_mod == 8)
		return (long_toa_base(va_arg(arg, long), base));
	if (data->len_mod == 16)
		return (llong_toa_base(va_arg(arg, long long), base));
	if (data->len_mod == 32)
		return (llong_toa_base(va_arg(arg, unsigned long long), base));
	return (int_toa_base(va_arg(arg, int), base));
}
