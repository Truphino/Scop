/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <trecomps@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:14:21 by trecomps          #+#    #+#             */
/*   Updated: 2016/01/06 17:19:35 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putwstr(wchar_t *str)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_wstrlen(str);
	while (i <= len)
	{
		ft_putwchar(str[i]);
		i++;
	}
}
