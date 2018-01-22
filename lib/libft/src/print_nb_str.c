/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nb_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <trecomps@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 11:39:35 by trecomps          #+#    #+#             */
/*   Updated: 2016/02/04 15:53:32 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_nb_str(char *nb, t_data *data, char *mod)
{
	int		i;

	if (data->prec == -1 && (data->flag & 2) != 0)
		i = data->field - (ft_strlen(nb) + ft_strnlen(mod));
	else
	{
		i = data->prec - ft_strlen(nb);
		if (nb[0] == '-' || nb[0] == '+' || nb[0] == ' ')
			i++;
	}
	if (nb[0] == '-' || nb[0] == '+' || nb[0] == ' ')
	{
		ft_printchar(nb[0], data);
		nb++;
	}
	while (mod && *mod)
		ft_printchar(*(mod++), data);
	while (i-- > 0)
		ft_printchar('0', data);
	while (*nb)
		ft_printchar(*(nb++), data);
}
