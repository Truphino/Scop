/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 10:46:45 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/03/14 16:02:15 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAMERA_H
# define __CAMERA_H

# include "vector.h"
# include "transform.h"
# include "window.h"
# include "film.h"
# include "matrix.h"

typedef struct
{
	int				flags;
	int				visualize_bboxes;
	t_transform		transformation;
	t_matrix		view_matrix;
	t_matrix		inverse_view_matrix;
	t_vector		origin;
	t_vector		direction;
	t_vector		eye;
	t_vector		up;
	t_vector		right;
	double			fov;
	double			half_width;
	double			half_height;
	double			pixel_width;
	double			pixel_height;
	int				sh_grain;
	int				anti_aliasing;
	t_film			film;

	GLuint			uniTrans;
}					t_camera;

void				default_camera(t_camera *camera);
void				initialize_camera(t_camera *camera, t_window *window);
void				apply_camera_transform(t_camera *camera,
											t_transform transf);
#endif
