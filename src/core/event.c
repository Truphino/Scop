/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 18:49:24 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/03/13 13:01:08 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

void			poll_events(t_scene *scene)
{
	int			quit;
	t_window	*window;

	window = &scene->window;
	quit = 0;
	while (!quit)
	{
		while (SDL_PollEvent(&SDL_EVENT))
		{
			if (SDL_EVENT.type == SDL_QUIT ||
			KEY == SDLK_ESCAPE)
			{
				quit = 1;
				kill_sdl(scene, "", 2);
			}
			if (KEY == SDLK_s)
				screen_shot(scene);
			if (KEY == SDLK_r)
			{
				glClearColor(1, 0, 0, 1);
				glClear(GL_COLOR_BUFFER_BIT);
				glDrawArrays(GL_TRIANGLES, 0, 6);
				SDL_GL_SwapWindow(SDL_WINDOW);
			}
			if (KEY == SDLK_g)
			{
				glClearColor(0, 1, 0, 1);
				glClear(GL_COLOR_BUFFER_BIT);
				glDrawArrays(GL_TRIANGLES, 0, 6);
				SDL_GL_SwapWindow(SDL_WINDOW);
			}
			if (KEY == SDLK_b)
			{
				glClearColor(0, 0, 1, 1);
				glClear(GL_COLOR_BUFFER_BIT);
				glDrawArrays(GL_TRIANGLES, 0, 6);
				SDL_GL_SwapWindow(SDL_WINDOW);
			}
		}
	}
}
