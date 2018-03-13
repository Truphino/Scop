/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_mesh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/13 16:05:06 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

t_mesh		*new_mesh(void)
{
	t_mesh *m;

	m = malloc(sizeof(t_mesh));
	m->bbox = new_bbox();
	m->material = new_material();
	m->obj_data = new_obj_data();
	m->affine_group = new_affine_group();
	return (m);
}
