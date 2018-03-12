/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 10:50:42 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/03/12 10:55:09 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ENUMS_H
# define __ENUMS_H

enum	e_file_types
{
	OBJ,
	NO_FORMAT,
};

enum	e_axis
{
	X_AXIS,
	Y_AXIS,
	Z_AXIS,
};

enum				e_shapes
{
	PLANE,
	SPHERE,
	CONE,
	CYLINDER,
	TRIANGLE,
	CUBE,
	MESH,
	LIGHT,
};

enum				e_hits
{
	BASE = 1,
	CAP = 2,
	SIDE = 3,
};

#endif
