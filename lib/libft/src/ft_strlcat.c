/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:30:10 by trecomps          #+#    #+#             */
/*   Updated: 2015/11/28 17:06:19 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		i;
	size_t		end_dst;
	size_t		j;

	j = 0;
	i = 0;
	while (dest[i] && i < size)
		i++;
	end_dst = i;
	while (src[j] && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (size > end_dst)
		dest[i] = '\0';
	return (end_dst + ft_strlen(src));
}
