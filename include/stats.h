/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:42:56 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/03/12 10:55:12 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __STATS_H
# define __STATS_H

typedef	struct	s_stats
{
	clock_t		tic;
	clock_t		toc;
	double		parse_time;
	double		render_time;
	int			total_intersections;
	int			primitives;
}				t_stats;

void			initialize_stats(t_stats *stats);
void			display_stats(t_stats stats);

#endif
