/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cannonical2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/12 10:57:17 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

t_cube	*new_canonical_cube(void)
{
	t_cube	*cube;

	cube = malloc(sizeof(t_cube));
	cube->flags = 0;
	return (cube);
}
