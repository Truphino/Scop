/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 18:31:31 by dgaitsgo          #+#    #+#             */
/*   Updated: 2018/03/12 10:57:22 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

void		free_node(t_node *node)
{
	if (node)
	{
		free_node(node->left);
		free_node(node->right);
		if (node->object)
		{
			if (node->object->material.texture.type == EXTERN)
				SDL_FreeSurface(node->object->material.texture.text_img);
			free(node->object);
		}
		free(node);
	}
}
