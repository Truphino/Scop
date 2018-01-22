/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <trecomps@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 13:58:31 by trecomps          #+#    #+#             */
/*   Updated: 2016/02/02 18:35:41 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printstr(char *str, t_data *data)
{
	int		prec;

	prec = data->prec;
	while (prec != 0 && *str)
	{
		ft_printchar(*str, data);
		prec--;
		str++;
	}
}
