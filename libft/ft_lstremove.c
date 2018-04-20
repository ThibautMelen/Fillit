/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 16:10:40 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/11 16:55:54 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstclr(t_list *elem)
{
	free(elem->content);
	free(elem);
}

void		ft_lstremove(t_list **plist, t_list *elem)
{
	t_list *tmp;
	t_list *next;

	if (plist == NULL || elem == NULL)
		return ;
	if (elem == *plist)
	{
		next = (*plist)->next;
		ft_lstclr(*plist);
		*plist = next;
		return ;
	}
	tmp = *plist;
	while (tmp->next != NULL)
	{
		if (tmp->next == elem)
		{
			next = tmp->next->next;
			ft_lstclr(tmp->next);
			tmp->next = next;
			return ;
		}
		tmp = tmp->next;
	}
}
