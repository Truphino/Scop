/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 14:19:09 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/14 16:30:30 by trecomps         ###   ########.fr       */
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
		printf("%d\t%d\t%d\t%d\n",
				obj->face_indexes[i * 4],
				obj->face_indexes[(i * 4) + 1],
				obj->face_indexes[(i * 4) + 2],
				obj->face_indexes[(i * 4) + 3]);
		i++;
	}
}

t_obj_data		*load_object()
{
	t_obj_data	*obj;

	obj = (t_obj_data *)ft_memalloc(sizeof(t_obj_data));
	load_mesh(obj, "./object_files/42.obj");
	triangulate_obj(obj);
	//print_loaded_obj(obj);

	return (obj);
}

void		hello_triangle(t_scene *scene)
{
	t_obj_data	*od;
	float		*obj_colours;
	t_window	*win;
	GLfloat		gl_matrix[16];

	scene->camera.transformation.translation.z -= 2;

	win = &scene->window;
	od = load_object();
	scene->od = od;
	obj_colours = generate_vbo(od);

	float points[] = {
	0.5f, 0.4f, 0.0f,
	0.5f, -0.5f, 0.0f,
	-0.4f, -0.5f, 0.0f,
	-0.5f, 0.5f, 0.0f,
	0.4f, 0.5f, 0.0f,
	-0.5f, -0.4f, 0.0f,
	};

	float colours[] = {
	1.0f, 1.0f,  1.0f,
	1.0f, 1.0f,  1.0f,
	1.0f, 1.0f,  1.0f,
	0.0f, 0.0f,  0.0f,
	0.0f, 0.0f,  0.0f,
	0.0f, 0.0f,  0.0f,
	};

	GLuint point_vbo = 0;
	glGenBuffers(1, &point_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, point_vbo);
	/*glBufferData(GL_ARRAY_BUFFER, sizeof(float) * od->n_triangle * 3,
			od->triangle_vertices,
			GL_STATIC_DRAW);*/
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 18,
			points,
			GL_STATIC_DRAW);

	GLuint colours_vbo = 0;
	glGenBuffers(1, &colours_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, colours_vbo);
/*	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * od->n_triangle * 3,
			obj_colours,
			GL_STATIC_DRAW);
*/	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 18,
			colours,
			GL_STATIC_DRAW);

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

//	glEnable(GL_CULL_FACE);
//	glCullFace(GL_BACK);
//	glFrontFace(GL_CW);

	glClearColor(0.6, 0.6, 0.8, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glUseProgram(shader_programme);

	scene->camera.uniTrans = glGetUniformLocation(shader_programme, "trans");
	glUniformMatrix4fv(scene->camera.uniTrans, 1, GL_FALSE,
			opengl_matrix(gl_matrix, scene->camera.inverse_view_matrix));

	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, od->n_triangle);
	SDL_GL_SwapWindow(win->window);

}
