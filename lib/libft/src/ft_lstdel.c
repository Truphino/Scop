/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:40:03 by trecomps          #+#    #+#             */
/*   Updated: 2015/11/27 18:08:24 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*tmp;
	t_list		*nxt;

	tmp = *alst;
	while (tmp)
	{
		nxt = tmp->next;
		del(tmp->content, tmp->content_size);
		free(tmp);
		tmp = nxt;
	}
	*alst = NULL;
}
