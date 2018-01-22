/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:05:33 by trecomps          #+#    #+#             */
/*   Updated: 2015/11/28 16:33:56 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_nb_w(char const *s, char c)
{
	int		nb;

	nb = 0;
	while (*s)
	{
		if (*s != c)
			nb++;
		while (*s != c && *s != '\0')
			s++;
		while (*s == c)
			s++;
	}
	return (nb);
}

static char		*ft_get_one(char const *s, char c)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (ft_strsub(s, 0, len));
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		nb;
	int		cur_word;

	cur_word = 0;
	nb = ft_nb_w(s, c);
	tab = (char **)malloc(sizeof(*tab) * nb + 1);
	if (!tab)
		return (NULL);
	tab[nb] = 0;
	while (cur_word < nb)
	{
		if (*s != c)
		{
			tab[cur_word] = ft_get_one(s, c);
			cur_word++;
		}
		while (*s != c && *s != '\0')
			s++;
		while (*s == c)
			s++;
	}
	return (tab);
}
