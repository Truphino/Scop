/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:22:21 by trecomps          #+#    #+#             */
/*   Updated: 2016/01/05 12:02:11 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;
	int		cmp;

	cmp = 0;
	i = 0;
	while (cmp == 0)
	{
		cmp = ft_abs(s1[i]) - ft_abs(s2[i]);
		if (cmp != 0)
			return (cmp);
		i++;
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
	}
	return (cmp);
}
