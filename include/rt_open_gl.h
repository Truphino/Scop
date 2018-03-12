/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_open_gl.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:40:18 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/03/12 10:55:12 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RT_OPEN_GL_H
# define __RT_OPEN_GL_H

# include <OpenGL/gl.h>
# include <OpenGL/glu.h>

void	sdl_surface_to_open_gl_texture(SDL_Surface *surface);

#endif
