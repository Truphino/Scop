/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:23:49 by trecomps          #+#    #+#             */
/*   Updated: 2016/01/05 12:03:55 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;

	i = 0;
	while (s[i])
		i++;
	while (s + i != s)
	{
		if (s[i] == c)
			return ((char *)s + i);
		i--;
	}
	if (s + i == s && s[i] == c)
		return ((char *)s);
	return (NULL);
}
