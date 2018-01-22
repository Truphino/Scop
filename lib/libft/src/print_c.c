/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <trecomps@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 12:59:51 by trecomps          #+#    #+#             */
/*   Updated: 2016/02/08 18:47:01 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			no_valid_conv(t_data *data, wchar_t c)
{
	int		i;

	if (!c)
		return (-1);
	i = data->field - sizewchar(c);
	if ((data->flag & 4) != 0)
		ft_printwchar(c, data);
	while (i-- > 0)
		ft_printchar(' ', data);
	if ((data->flag & 4) == 0)
		ft_printwchar(c, data);
	return (1);
}

int			print_c(t_data *data, va_list arg)
{
	int		i;

	i = data->field;
	if (data->len_mod == 8)
		return (print_lc(data, arg));
	if ((data->flag & 4) != 0)
		ft_printchar((char)va_arg(arg, int), data);
	while (--i > 0)
		ft_printchar((data->flag & 2) ? '0' : ' ', data);
	if ((data->flag & 4) == 0)
		ft_printchar((char)va_arg(arg, int), data);
	return (1);
}

int			print_lc(t_data *data, va_list arg)
{
	int		i;
	int		c;

	c = va_arg(arg, int);
	i = data->field - sizewchar(c);
	if ((data->flag & 4) != 0)
		ft_printwchar(c, data);
	while (i-- > 0)
		ft_printchar(' ', data);
	if ((data->flag & 4) == 0)
		ft_printwchar(c, data);
	return (1);
}
