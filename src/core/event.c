/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 18:49:24 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/03/14 16:19:47 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

void			poll_events(t_scene *scene)
{
	int			quit;
	t_window	*window;
	GLfloat		gl_matrix[16];

	window = &scene->window;
	quit = 0;
	while (!quit)
	{
		while (SDL_PollEvent(&SDL_EVENT))
		{
			apply_camera_transform(&scene->camera, scene->camera.transformation);
			glUniformMatrix4fv(scene->camera.uniTrans, 1, GL_FALSE,
					opengl_matrix(gl_matrix, scene->camera.inverse_view_matrix));

			glClear(GL_COLOR_BUFFER_BIT);
			glDrawArrays(GL_TRIANGLES, 0, scene->od->n_triangle);
			SDL_GL_SwapWindow(SDL_WINDOW);

			if (SDL_EVENT.type == SDL_QUIT ||
			KEY == SDLK_ESCAPE)
			{
				quit = 1;
				kill_sdl(scene, "", 2);
			}
			if (KEY == SDLK_LEFT)
				scene->camera.transformation.rotation.y += 10;
			if (KEY == SDLK_RIGHT)
				scene->camera.transformation.rotation.y -= 10;
		}
	}
}
