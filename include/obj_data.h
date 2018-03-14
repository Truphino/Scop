/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:23:41 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/03/14 09:38:51 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __OBJ_DATA_H
# define __OBJ_DATA_H

# include "vector.h"

typedef struct	s_obj_data
{
	t_vector	*vertices;
	t_vector	*normals;
	t_vector	*face_indexes;
	t_vector	*normal_indexes;
	int			n_normal_indexes;
	int			n_vertices;
	int			n_normals;
	int			n_faces;
}				t_obj_data;

t_obj_data		*new_obj_data(void);
void			load_mesh(t_obj_data *od, char *file_name);

#endif
