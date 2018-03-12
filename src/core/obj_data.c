/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/12 10:57:22 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

t_obj_data		*new_obj_data(void)
{
	t_obj_data	*od;

	od = malloc(sizeof(t_obj_data));
	od->n_faces = 0;
	od->n_normals = 0;
	od->n_normal_indexes = 0;
	od->n_vertices = 0;
	return (od);
}
