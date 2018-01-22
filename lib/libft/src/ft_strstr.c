/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:35:50 by trecomps          #+#    #+#             */
/*   Updated: 2016/01/05 12:04:00 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	size_t	len;
	int		res;

	len = ft_strlen(s2);
	i = 0;
	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	if (ft_strlen(s1) < len)
	{
		return (NULL);
	}
	while (s1[i + len - 1])
	{
		if (s1[i] == s2[0])
		{
			res = ft_strncmp(s1 + i, s2, len);
			if (res == 0)
				return ((char *)s1 + i);
		}
		i++;
	}
	return (NULL);
}
