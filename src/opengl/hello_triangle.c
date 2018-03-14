/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 14:19:09 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/14 09:45:04 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"
#include "parse.h"

void			print_vector(t_vector v)
{
	printf("V.x:%f;\tV.y:%f;\tV.z:%f;\tV.w%f\n", v.x, v.y, v.z, v.w);
}

void			print_loaded_obj(t_obj_data *obj)
{
	int			i;

	i = 0;
	printf("Vertices: %u\nNormals: %u\nFaces: %u\n",
			obj->n_vertices,
			obj->n_normals,
			obj->n_faces);
	while (i < obj->n_faces)
	{
		printf("%f\t%f\t%f\t%f\n",
				obj->face_indexes[i].x,
				obj->face_indexes[i].y,
				obj->face_indexes[i].z,
				obj->face_indexes[i].w);
		i++;
	}
}

void			load_object()
{
	t_obj_data	*obj;

	obj = (t_obj_data *)ft_memalloc(sizeof(t_obj_data));
	load_mesh(obj, "./object_files/42.obj");
	//print_loaded_obj(obj);
}

void		hello_triangle(t_window *win)
{
	load_object();

	float points[] = {
	0.5f, 0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
	-0.5f, -0.5f, 0.0f,
	-0.5f, 0.5f, 0.0f,
	0.5f, 0.5f, 0.0f,
	-0.5f, -0.5f, 0.0f,
	};

	float colours[] = {
	1.0f, 1.0f,  1.0f,
	0.0f, 0.0f,  0.0f,
	1.0f, 1.0f,  1.0f,
	0.0f, 0.0f,  0.0f,
	1.0f, 1.0f,  1.0f,
	1.0f, 1.0f,  1.0f,
	};

	GLuint point_vbo = 0;
	glGenBuffers(1, &point_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, point_vbo);
	glBufferData(GL_ARRAY_BUFFER, 18 * sizeof(float), points, GL_STATIC_DRAW);

	GLuint colours_vbo = 0;
	glGenBuffers(1, &colours_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, colours_vbo);
	glBufferData(GL_ARRAY_BUFFER, 18 * sizeof(float), colours, GL_STATIC_DRAW);

	GLuint vao = 0;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, point_vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glBindBuffer(GL_ARRAY_BUFFER, colours_vbo);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	const char *v_shader = load_shader_file("./src/shaders/test.vert");
	const char	*fragment_shader = load_shader_file("./src/shaders/test.frag");

	if (fragment_shader == NULL || v_shader == NULL)
	{
		ft_putendl("Error while loading shader file");
		exit(1);
	}
	int vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &v_shader, NULL);
	compile_shader_log(vs);
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragment_shader, NULL);
	compile_shader_log(fs);

	GLuint shader_programme = glCreateProgram();
	glAttachShader(shader_programme, fs);
	glAttachShader(shader_programme, vs);
	link_program_log(shader_programme);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CW);

	glClearColor(0.6, 0.6, 0.8, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glUseProgram(shader_programme);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	SDL_GL_SwapWindow(win->window);

}
