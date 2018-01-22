/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:41:09 by trecomps          #+#    #+#             */
/*   Updated: 2015/11/24 17:04:00 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cpy;

	i = 0;
	if (n == 0)
		return (s);
	cpy = (unsigned char *)s;
	while (i < n)
	{
		cpy[i] = c;
		i++;
	}
	return (s);
}
