/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:50:35 by trecomps          #+#    #+#             */
/*   Updated: 2016/01/05 12:02:31 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *str)
{
	char	*cpy;
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	cpy = ft_strnew(i);
	if (cpy == NULL)
		return (NULL);
	ft_strcpy(cpy, str);
	return (cpy);
}
