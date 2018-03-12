/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/12 10:57:23 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

double			random_double(double max)
{
	double random;

	random = ((double)rand() / (double)(RAND_MAX)) * max;
	return (random);
}

int				random_int(double max)
{
	double random;

	random = ((double)rand() / (RAND_MAX)) * max;
	return ((int)random);
}

t_vector		random_color(void)
{
	return (init_color(random_int(255), random_int(255), random_int(255)));
}

t_material		random_material(void)
{
	t_material	material;

	material.lambert = random_double(0.4);
	material.specular = random_double(0.2);
	material.ambient = random_double(0.3);
	material.reflective = random_double(0.7);
	material.texture.color_1 = random_color();
	return (material);
}
