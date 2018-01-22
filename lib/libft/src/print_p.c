/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <trecomps@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 13:03:41 by trecomps          #+#    #+#             */
/*   Updated: 2016/02/08 17:47:35 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_p(t_data *data, va_list arg)
{
	data->flag = ((data->flag | 1) | 32);
	data->len_mod = 8;
	return (print_x(data, arg));
}
