/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:11:02 by trecomps          #+#    #+#             */
/*   Updated: 2015/11/28 19:47:54 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	int		pass_start;
	int		pass_end;
	int		i;
	char	*trim;

	i = 0;
	pass_start = 0;
	pass_end = 0;
	while (s[i] == '\n' || s[i] == ' ' || s[i] == '\t')
	{
		pass_start++;
		i++;
	}
	while (s[i + 1] && s[i])
		i++;
	while (s[i] == '\n' || s[i] == ' ' || s[i] == '\t')
	{
		i--;
		pass_end++;
	}
	trim = ft_strsub(s, pass_start, ft_strlen(s) - pass_start - pass_end);
	return (trim);
}
