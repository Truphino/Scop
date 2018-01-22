/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <trecomps@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:14:10 by trecomps          #+#    #+#             */
/*   Updated: 2016/01/06 17:18:01 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			ft_wstrlen(wchar_t *str)
{
	int			i;
	size_t		len;

	len = 0;
	i = 0;
	while (str[i])
	{
		i++;
		len++;
	}
	return (len);
}
