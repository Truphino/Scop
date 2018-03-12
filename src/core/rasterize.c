/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/12 10:57:23 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

t_vector	perspective_divide(t_vector v)
{
	t_vector	p;

	p = v;
	p.x = p.x / p.z;
	p.y = p.y / p.z;
	return (p);
}

void		rasterize(t_scene *scene)
{
	draw_all_bounding_boxes(scene);
}
