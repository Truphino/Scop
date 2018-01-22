/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:34:23 by trecomps          #+#    #+#             */
/*   Updated: 2016/01/05 12:03:14 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		cmp;

	i = 0;
	cmp = 0;
	while (i < n)
	{
		cmp = ft_abs(s1[i]) - ft_abs(s2[i]);
		if (cmp != 0)
			return (cmp);
		i++;
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
	}
	return (0);
}
