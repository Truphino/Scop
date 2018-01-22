/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:53:20 by trecomps          #+#    #+#             */
/*   Updated: 2015/11/28 13:47:48 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *cpy;

	cpy = (unsigned char *)malloc(sizeof(*cpy) * n);
	ft_memcpy(cpy, src, n);
	ft_memcpy(dest, cpy, n);
	free(cpy);
	return (dest);
}
