/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_helpers.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 10:52:30 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/03/12 10:55:10 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GRAPHICS_HELPERS_H
# define __GRAPHICS_HELPERS_H

double		clamp(double x, double min_value, double max_value);
double		smooth_step(double edge0, double edge1, double x);
t_vector	lerp(t_vector x, t_vector y, double a);

#endif
