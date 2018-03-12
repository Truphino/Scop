/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opengl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 12:23:19 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/12 12:39:56 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __OPENGL_H
# define __OPENGL_H

#include "window.h"

void			init_opengl();
void			setGlColor(t_window *win, float r, float g, float b, float a);

#endif
