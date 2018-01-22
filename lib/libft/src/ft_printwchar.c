/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printwchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <trecomps@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 13:20:10 by trecomps          #+#    #+#             */
/*   Updated: 2016/01/09 13:23:12 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printwchar(wchar_t c, t_data *data)
{
	if (c <= 127)
		ft_printchar(c, data);
	else if (c <= 2047)
	{
		ft_printchar(((c >> 6) & 31) | 192, data);
		ft_printchar((c & 63) | 128, data);
	}
	else if (c <= 65535)
	{
		ft_printchar(((c >> 12) & 15) | 224, data);
		ft_printchar(((c >> 6) & 63) | 128, data);
		ft_printchar((c & 63) | 128, data);
	}
	else if (c <= 2097151)
	{
		ft_printchar(((c >> 18) & 7) | 240, data);
		ft_printchar(((c >> 12) & 63) | 128, data);
		ft_printchar(((c >> 6) & 63) | 128, data);
		ft_printchar((c & 63) | 128, data);
	}
}
