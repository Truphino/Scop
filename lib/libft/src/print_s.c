/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <trecomps@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 12:55:54 by trecomps          #+#    #+#             */
/*   Updated: 2016/02/08 18:51:28 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int				print_s(t_data *data, va_list arg)
{
	int			i;
	char		*str;

	if (data->len_mod == 8)
		return (print_ls(data, arg));
	str = va_arg(arg, char *);
	if (!str)
	{
		ft_printstr("(null)", data);
		return (1);
	}
	if (data->prec != -1)
		i = data->field - ft_min(ft_strlen(str), data->prec);
	else
		i = data->field - ft_strlen(str);
	if ((data->flag & 4) != 0)
		ft_printstr(str, data);
	while (i-- > 0)
		ft_printchar((data->flag & 2) ? '0' : ' ', data);
	if ((data->flag & 4) == 0)
		ft_printstr(str, data);
	return (1);
}

int				print_ls(t_data *data, va_list arg)
{
	int			i;
	wchar_t		*str;

	str = va_arg(arg, wchar_t *);
	if (!str)
	{
		ft_printstr("(null)", data);
		return (1);
	}
	i = data->field - sizewstr(str);
	if ((data->flag & 4) != 0)
		ft_printwstr(str, data);
	while (i-- > 0)
		ft_printchar((data->flag & 2) ? '0' : ' ', data);
	if ((data->flag & 4) == 0)
		ft_printwstr(str, data);
	return (1);
}
