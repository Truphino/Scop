/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_get_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <trecomps@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 14:26:06 by trecomps          #+#    #+#             */
/*   Updated: 2016/02/08 18:35:41 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		len_mod(char *str, t_data *data)
{
	char		*ln_mod;
	int			i;

	i = 0;
	ln_mod = "hh\0ll\0h\0\0l\0\0j\0\0z\0\0";
	while (i < 6)
	{
		if (ft_strncmp(ln_mod + (i * 3), str + data->len_for,
					ft_strlen(ln_mod + (i * 3))) == 0)
		{
			data->len_for += ft_strlen(ln_mod + (i * 3));
			data->len_mod = ft_pow(2, i);
			return (1);
		}
		i++;
	}
	return (-1);
}

static int		prec(char *str, t_data *data)
{
	if (str[data->len_for] == '.')
	{
		data->len_for++;
		data->prec = ft_atoi(str + data->len_for);
		while (ft_isdigit(str[data->len_for]))
			data->len_for++;
		return (1);
	}
	return (-1);
}

static int		field(char *str, t_data *data)
{
	if (ft_isdigit(str[data->len_for]))
	{
		data->field = ft_atoi(str + data->len_for);
		while (ft_isdigit(str[data->len_for]))
			data->len_for++;
		return (1);
	}
	return (-1);
}

static int		flag(char *str, t_data *data)
{
	char		*flag;
	int			j;

	flag = "#0-+ ";
	while (str[data->len_for] && (j = ft_strpos(flag, str[data->len_for])) > -1)
	{
		data->flag = data->flag | ft_pow(2, j);
		data->len_for++;
	}
	if (data->flag == 0)
		return (-1);
	return (1);
}

int				new_get_flag(char *str, t_data *data)
{
	char	*conv;

	conv = "sSpdDioOuUxXcC%";
	data->len_for++;
	flag(str, data);
	field(str, data);
	prec(str, data);
	len_mod(str, data);
	if (!str[data->len_for] || !ft_strchr(conv, str[data->len_for]))
	{
		if (str[data->len_for])
			data->len_for++;
		return (0);
	}
	if ((data->flag & 2) && (data->flag & 4))
		data->flag = data->flag - 2;
	if ((data->flag & 8) && (data->flag & 16))
		data->flag = data->flag - 16;
	data->len_for++;
	return (1);
}
