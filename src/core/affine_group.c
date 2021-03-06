/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affine_group.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/12 10:57:17 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

t_affine_group		new_affine_group(void)
{
	t_affine_group ag;

	default_transformation(&ag.trans_data);
	build_transformation_matrix(ag.transformation, ag.trans_data);
	build_inverse_transformation_matrix(ag.inverse, ag.trans_data);
	build_normal_to_world(ag.inverse_scale_times_rotation, ag.trans_data);
	return (ag);
}
