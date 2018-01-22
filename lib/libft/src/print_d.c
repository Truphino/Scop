/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <trecomps@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 13:02:10 by trecomps          #+#    #+#             */
/*   Updated: 2016/02/08 16:40:49 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_d(t_data *data, va_list arg)
{
	char	*nb;
	int		i;

	i = data->field;
	nb = what_conv(arg, data, 10);
	if (ft_strcmp(nb, "0") == 0 && data->prec == 0)
		ft_str_empty(nb);
	if ((data->flag & 8) != 0 && nb[0] != '-')
		nb = ft_strjoin("+", nb);
	if ((data->flag & 16) != 0 && nb[0] != '-')
		nb = ft_strjoin(" ", nb);
	if (nb)
		i = data->field - ft_max(ft_strlen(nb), data->prec + !ft_isnb(nb[0]));
	if (data->prec != -1 && ((data->flag & 2) != 0))
		data->flag = data->flag - 2;
	if ((data->flag & 4) != 0)
		print_nb_str(nb, data, NULL);
	while ((i-- > 0) && (data->flag & 2) == 0)
		ft_printchar(' ', data);
	if ((data->flag & 4) == 0)
		print_nb_str(nb, data, NULL);
	free(nb);
	return (1);
}

int			print_ld(t_data *data, va_list arg)
{
	data->len_mod = 8;
	return (print_d(data, arg));
}
