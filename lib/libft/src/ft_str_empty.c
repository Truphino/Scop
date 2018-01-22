/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_empty.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <trecomps@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 18:45:31 by trecomps          #+#    #+#             */
/*   Updated: 2016/02/04 18:49:14 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_str_empty(char *str)
{
	free(str);
	if ((str = (char *)ft_memalloc(1)) == NULL)
		return (NULL);
	return (str);
}
