/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_primary_ray.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:02:03 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/03/12 10:57:20 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

t_ray			generate_primary_ray(t_camera *camera, double x, double y)
{
	t_ray		ray;
	t_vector	view_plane_x;
	t_vector	view_plane_y;

	ray.type = PRIMARY;
	view_plane_x =
	vector_scale(camera->right,
			((x + 0.5) * camera->pixel_width) - camera->half_width);
	view_plane_y =
	vector_scale(camera->up,
			((y + 0.5) * camera->pixel_height) - camera->half_height);
	ray.origin = camera->origin;
	ray.direction =
	unit_vector(vector_add(camera->eye,
				vector_add(view_plane_x, view_plane_y)));
	return (ray);
}
