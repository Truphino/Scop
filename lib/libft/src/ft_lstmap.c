/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:19:54 by trecomps          #+#    #+#             */
/*   Updated: 2015/11/26 18:41:33 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*map;
	t_list	*mark;
	t_list	*tmp;

	mark = lst;
	if (mark)
	{
		map = (*f)(mark);
		if (!map)
			return (NULL);
		mark = mark->next;
	}
	else
		return (NULL);
	while (mark)
	{
		tmp = (*f)(mark);
		if (!tmp)
			return (NULL);
		ft_lstaddend(&map, tmp);
		mark = mark->next;
	}
	return (map);
}
