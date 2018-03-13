/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opengl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 12:23:19 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/13 11:57:58 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __OPENGL_H
# define __OPENGL_H

# include "window.h"

# define GL_LOG_FILE "./gl.log"

void			init_opengl();
void			setGlColor(t_window *win, float r, float g, float b, float a);
void			hello_triangle(t_window *window);
char			*load_shader_file(char *filename);
int				restart_log();
int				gl_log();
int				compile_shader_log(GLuint shader_index);
int				link_program_log(GLuint program);
void			print_shader_info_log(GLuint index);
void			print_program_info_log(GLuint index);

#endif
