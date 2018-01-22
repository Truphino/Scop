/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:13:25 by trecomps          #+#    #+#             */
/*   Updated: 2016/01/05 12:03:39 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	len;
	size_t	res;

	i = 0;
	len = (size_t)ft_strlen(s2);
	if ((size_t)ft_strlen(s1) < len || len > n)
		return (NULL);
	if (n > (size_t)ft_strlen(s1))
		return (ft_strstr(s1, s2));
	while (i < n)
	{
		if (len > n - i)
			return (NULL);
		res = ft_strncmp(s1 + i, s2, len);
		if (res == 0)
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
