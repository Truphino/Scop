/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pares_mesh2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:15:15 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/03/14 09:49:44 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_data.h"
#include "parse.h"

void		fetch_obj_data_mem(t_obj_data *od)
{
	od->vertices = malloc(sizeof(t_vector) * od->n_vertices);
	od->normals = malloc(sizeof(t_vector) * od->n_normals);
	od->face_indexes = malloc(sizeof(t_vector) * od->n_faces);
	od->normal_indexes = malloc(sizeof(int) * od->n_faces);
	ft_memset(od->face_indexes, 0, od->n_faces);
	ft_memset(od->normal_indexes, 0, od->n_faces);
}

void		push_obj_vertex(t_obj_data *od, char **line)
{
	char **tokens;

	tokens = ft_strsplit(*line, ' ');
	od->vertices[od->n_vertices].x = atof(tokens[1]);
	od->vertices[od->n_vertices].y = atof(tokens[2]);
	od->vertices[od->n_vertices].z = atof(tokens[3]);
	od->vertices[od->n_vertices].w = 1.0f;
	od->n_vertices++;
	multi_free_4(tokens[0], tokens[1], tokens[2], tokens[3]);
	free(tokens);
}

void		push_obj_normal(t_obj_data *od, char **line)
{
	char **tokens;

	tokens = ft_strsplit(*line, ' ');
	od->normals[od->n_normals].x = atof(tokens[1]);
	od->normals[od->n_normals].y = atof(tokens[2]);
	od->normals[od->n_normals].z = atof(tokens[3]);
	od->normals[od->n_normals].w = 1.0f;
	od->n_normals++;
	multi_free_4(tokens[0], tokens[1], tokens[2], tokens[3]);
	free(tokens);
}

int			handle_no_normal_in_f(char **sub_field_tokens)
{
	int		normal_field;

	normal_field = 0;
	if (sub_field_tokens[0] != NULL)
	{
		if (sub_field_tokens[1] == NULL)
		{
			normal_field = 0;
		}
		else
		{
			if (sub_field_tokens[2] == NULL)
			{
				normal_field = 1;
			}
			else
			{
				normal_field = 2;
			}
		}
	}
	return normal_field;
}

void		free_sub_field_token(char **sub_field_tokens, int normal_field)
{
	int		i;

	i = normal_field;
	free_if(sub_field_tokens[i]);
	i--;
	if (i >= 0)
		free_if(sub_field_tokens[i]);
	i--;
	if (i >= 0)
		free_if(sub_field_tokens[i]);
}

void		push_obj_face_data(t_obj_data *od, char **line)
{
	char	**tokens;
	char	**sub_field_tokens;
	int		normal_field;

	tokens = ft_strsplit(*line, ' ');
	od->face_indexes[od->n_faces].x = atof(tokens[1]) - 1;
	od->face_indexes[od->n_faces].y = atof(tokens[2]) - 1;
	od->face_indexes[od->n_faces].z = atof(tokens[3]) - 1;
	if (tokens[4])
		od->face_indexes[od->n_faces].w = atof(tokens[4]) - 1;
	else
		od->face_indexes[od->n_faces].w = -1.0f;
	od->n_faces += 1;
	sub_field_tokens = ft_strsplit(tokens[1], '/');
	normal_field = sub_field_tokens[2] == NULL ? 1 : 2;
	normal_field = handle_no_normal_in_f(sub_field_tokens);
	/*if (normal_field > 0)
		od->normal_indexes[od->n_normal_indexes] =
			atof(sub_field_tokens[normal_field]) - 1;
	else
		od->normal_indexes[od->n_normal_indexes] = -1;
	od->n_normal_indexes += 1;*/
	multi_free_4(tokens[0], tokens[1], tokens[2], tokens[3]);
	free_sub_field_token(sub_field_tokens, normal_field);
	free(tokens);
	free(sub_field_tokens);
}

int			load_faces_indexes(t_obj_data *od, char **tokens)
{
	od->face_indexes[od->n_faces].x = -1;
	od->face_indexes[od->n_faces].y = -1;
	od->face_indexes[od->n_faces].z = -1;
	od->face_indexes[od->n_faces].w = -1;
	if (tokens[1])
	{
		od->face_indexes[od->n_faces].x = atof(tokens[1]) - 1;
		if (tokens[2])
		{
			od->face_indexes[od->n_faces].y = atof(tokens[2]) - 1;
			if (tokens[3])
			{
				od->face_indexes[od->n_faces].y = atof(tokens[3]) - 1;
				if (tokens[4])
				{
					od->face_indexes[od->n_faces].y = atof(tokens[4]) - 1;
					return 4;
				}
				return 3;
			}
			return 2;
		}
		return 1;
	}
	od->n_faces++;
	return 0;
}

void		load_normal_indexes(t_obj_data *od, char **tokens)
{
	
}

void		push_obj_face_data_2(t_obj_data *od, char **line)
{
	char	**tokens;
	char	**sub_field_tokens;
	int		normal_field;
	int		i;

	tokens = ft_strsplit(*line, ' ');
	load_faces_indexes(od, tokens);
	sub_field_tokens = ft_strsplit(tokens[1], '/');
	normal_field = sub_field_tokens[2] == NULL ? 1 : 2;
	normal_field = handle_no_normal_in_f(sub_field_tokens);
	od->n_normal_indexes += 1;
	multi_free_4(tokens[0], tokens[1], tokens[2], tokens[3]);
	free_sub_field_token(sub_field_tokens, normal_field);
	free(tokens);
	free(sub_field_tokens);
}

void		load_obj(t_obj_data *od, const int fd)
{
	char	*line;

	line = NULL;
	fetch_obj_data_mem(od);
	reset_counter(od);
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == 'v' && line[1] == ' ')
		{
			push_obj_vertex(od, &line);
		}
		else if (line[0] == 'v' && line[1] == 'n')
		{
			push_obj_normal(od, &line);
		}
		else if (line[0] == 'f')
		{
			push_obj_face_data_2(od, &line);
		}
		free_if(line);
	}
	free_if(line);
}
