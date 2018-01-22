/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printwstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <trecomps@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 14:48:46 by trecomps          #+#    #+#             */
/*   Updated: 2016/01/09 15:04:09 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printwstr(wchar_t *str, t_data *data)
{
	int		i;
	int		prec;

	i = 0;
	prec = sizewstr(str);
	if (data->prec > 0)
		prec = data->prec;
	while (str[i] && prec >= sizewchar(str[i]))
	{
		ft_printwchar(str[i], data);
		prec -= sizewchar(str[i]);
		i++;
	}
}
