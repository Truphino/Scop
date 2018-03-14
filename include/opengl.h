/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opengl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 12:23:19 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/14 15:27:54 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __OPENGL_H
# define __OPENGL_H

# include "window.h"

# define GL_LOG_FILE "./gl.log"

void			init_opengl();
void			setGlColor(t_window *win, float r, float g, float b, float a);
char			*load_shader_file(char *filename);
int				restart_log();
int				gl_log();
int				compile_shader_log(GLuint shader_index);
int				link_program_log(GLuint program);
void			print_shader_info_log(GLuint index);
void			print_program_info_log(GLuint index);
void			triangulate_obj(t_obj_data *od);
float			*generate_vbo(t_obj_data *od);

GLfloat			*opengl_matrix(GLfloat *gl_matrix, t_matrix matrix);

#endif
