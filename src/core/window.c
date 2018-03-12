/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/12 16:21:51 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

t_vector		get_pixel_color(t_window *window, char *img, int x, int y)
{
	t_vector	color;
	int			i;

	i = (x * SDL_DEPTH >> 3) + y * SDL_BPL;
	color.x = img[i];
	color.y = img[i + 1];
	color.z = img[i + 2];
	color.w = img[i + 3];
	rgb_to_normal(&color);
	return (color);
}

void			initialize_window(t_window *window)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		printf("Coundn't init sdl\n");
	init_opengl();
	SDL_WIDTH = SDL_WIDTH ? SDL_WIDTH : DEFAULT_WINDOW_WIDTH;
	SDL_HEIGHT = SDL_HEIGHT ? SDL_HEIGHT : DEFAULT_WINDOW_HEIGHT;
	SDL_DEPTH = 32;
	SDL_BPL = SDL_WIDTH * (SDL_DEPTH / 8);
	SDL_WINDOW = SDL_CreateWindow("ray tracing", 100, 200,
	SDL_WIDTH, SDL_HEIGHT, SDL_WINDOW_OPENGL);
	SDL_FRAME_BUFFER = malloc(SDL_WIDTH * SDL_HEIGHT * 4);
	window->z_buffer = malloc(sizeof(double) * SDL_WIDTH * SDL_HEIGHT);
	window->aspect_ratio = (double)SDL_WIDTH / (double)SDL_HEIGHT;
	window->inverse_aspect_ratio = (double)SDL_HEIGHT / (double)SDL_WIDTH;
	if ((window->gl_context = SDL_GL_CreateContext(SDL_WINDOW)) == NULL)
		printf("Cannot init gl context\n");
	glewExperimental = GL_TRUE;
	glewInit();
}

void			kill_sdl(t_scene *scene, char *str, int fd)
{
	t_window	*window;

	window = &scene->window;
	SDL_GL_DeleteContext(window->gl_context);
	SDL_DestroyWindow(SDL_WINDOW);
	SDL_Quit();
	ft_putstr_fd(str, fd);
	exit(0);
}

void			put_pixel(t_window *window,
				t_vector pos, t_vector color, int depth_test)
{
	int i;
	int	zindex;

	zindex = (int)pos.y + window->width + (int)pos.x;
	i = ((int)pos.x * SDL_DEPTH >> 3) + (int)pos.y * SDL_BPL;
	if (pos.x < 0 || pos.x >= window->width ||
		pos.y < 0 || pos.y >= window->height)
		return ;
	if (color.x < 0 || color.x > 255)
		return ;
	if (color.y < 0 || color.y > 255)
		return ;
	if (color.z < 0 || color.z > 255)
		return ;
	SDL_FRAME_BUFFER[i] = color.z;
	SDL_FRAME_BUFFER[i + 1] = color.y;
	SDL_FRAME_BUFFER[i + 2] = color.x;
	SDL_FRAME_BUFFER[i + 3] = 1;
	window->z_buffer[(int)pos.y + window->width + (int)pos.x] = pos.z;
}

void			put_image(t_scene *scene)
{
	t_window	*window;

	window = &scene->window;
	setGlColor(window, 0, 1, 1, 1);

	hello_triangle(window);

	poll_events(scene);
}
