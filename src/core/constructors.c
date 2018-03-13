/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/13 16:01:34 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"
#include "parse.h"

void				fetch_shape(t_object *object, int type)
{
	if (type == PLANE)
		object->shape = new_canonical_plane();
	if (type == SPHERE)
		object->shape = new_canonical_sphere();
	if (type == CYLINDER)
		object->shape = new_canonical_cylinder();
	if (type == CONE)
		object->shape = new_canonical_cone();
	if (type == TRIANGLE)
		object->shape = new_canonical_triangle();
	if (type == CUBE)
		object->shape = new_canonical_cube();
	if (type == CSG_ELEM)
		object->shape = new_csg();
}
