/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/12 10:57:21 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

t_light				*new_light(int shape)
{
	t_light			*light;

	light = malloc(sizeof(t_light));
	light->shape = shape;
	set_vector(&light->position, 0, 0, 0);
	set_vector(&light->color, 255, 255, 255);
	return (light);
}

void				default_light(t_light *light)
{
	light->color = new_vector(255, 255, 255);
	light->position = new_vector(0, 0, 0);
}
