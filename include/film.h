/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   film.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 19:04:02 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/03/12 10:55:09 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILM_H
# define __FILM_H

# include "tone_map.h"

struct s_palette;

typedef struct
{
	int					quantize;
	int					ldr;
	t_tone_map			tone_map;
	struct s_palette	**color_map;
}						t_film;

#endif
