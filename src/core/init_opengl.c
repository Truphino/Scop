/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_opengl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 11:46:03 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/12 16:23:40 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

void		init_opengl()
{
	SDL_GL_SetAttribute(
		SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE
	);
	if (SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4) != 0)
		printf("%s\n", SDL_GetError());
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	SDL_GL_SetSwapInterval(1);
}

void		setGlColor(t_window *window, float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT);
	SDL_GL_SwapWindow(SDL_WINDOW);
}

void		hello_triangle(t_window *win)
{
	float points[] = {
	0.0f, 0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
	-0.5f, -0.5f, 0.0f
	};

	GLuint vbo = 0;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), points, GL_STATIC_DRAW);

	GLuint vao = 0;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	const char* vertex_shader =
	"#version 410\n"
	"in vec3 vp;"
	"void main() {"
	"  gl_Position = vec4(vp, 1.0);"
	"}";

	const char* fragment_shader =
	"#version 410\n"
	"out vec4 frag_colour;"
	"void main() {"
	"  frag_colour = vec4(0.5, 0.0, 0.5, 1.0);"
	"}";

	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertex_shader, NULL);
	glCompileShader(vs);
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragment_shader, NULL);
	glCompileShader(fs);

	GLuint shader_programme = glCreateProgram();
	glAttachShader(shader_programme, fs);
	glAttachShader(shader_programme, vs);
	glLinkProgram(shader_programme);

	glClearColor(0.6, 0.6, 0.6, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glUseProgram(shader_programme);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	SDL_GL_SwapWindow(win->window);

}
