/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizewstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <trecomps@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 14:41:12 by trecomps          #+#    #+#             */
/*   Updated: 2016/01/09 14:43:29 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			sizewstr(wchar_t *str)
{
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	while (str[i])
	{
		ret += sizewchar(str[i]);
		i++;
	}
	return (ret);
}
