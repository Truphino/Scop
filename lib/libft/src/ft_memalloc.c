/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:43:53 by trecomps          #+#    #+#             */
/*   Updated: 2016/01/05 12:04:27 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*data;
	size_t			i;

	i = 0;
	data = (unsigned char *)malloc(size);
	if (!data)
		return (NULL);
	while (i < size)
	{
		data[i] = 0;
		i++;
	}
	return (data);
}
