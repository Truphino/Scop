/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 18:56:20 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/03/12 10:55:10 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIGHT_H
# define __LIGHT_H

# include "object.h"
# include "vector.h"

typedef struct	s_light
{
	t_vector	position;
	t_transform	transformation;
	t_vector	color;
	t_matrix	transformation_matrix;
	int			type;
	int			shape;
}				t_light;

enum	e_light
{
	POINT,
	AREA,
};

t_light			*new_light(int shape);
void			default_light(t_light *light);

#endif
