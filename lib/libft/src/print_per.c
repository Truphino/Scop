/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pour.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <trecomps@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 12:57:14 by trecomps          #+#    #+#             */
/*   Updated: 2016/02/08 14:16:01 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_per(t_data *data, va_list arg)
{
	int		i;
	char	space;

	(void)arg;
	i = data->field;
	space = ' ';
	if (data->flag & 2)
		space = '0';
	if ((data->flag & 4) != 0)
		ft_printchar('%', data);
	while (--i > 0)
		ft_printchar(space, data);
	if ((data->flag & 4) == 0)
		ft_printchar('%', data);
	return (1);
}
