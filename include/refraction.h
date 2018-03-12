/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refraction.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 10:56:56 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/03/12 10:55:12 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __REFRACTION_H
# define __REFRACTION_H

typedef struct
{
	double	density_1;
	double	density_2;
	double	n;
	double	cos_i;
	double	cos_t2;
	double	sin_t2;
	double	transmittance;
	double	reflectance;
}			t_refraction_data;

#endif
