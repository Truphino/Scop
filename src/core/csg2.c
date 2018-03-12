/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csg2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:27:10 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/12 10:57:18 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

t_node		*new_csg(void)
{
	t_node	*ret;

	if ((ret = (t_node *)ft_memalloc(sizeof(t_node))) == NULL)
		return (NULL);
	ret->left = NULL;
	ret->right = NULL;
	return (ret);
}
