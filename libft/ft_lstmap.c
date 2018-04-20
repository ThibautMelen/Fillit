/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 14:33:57 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/05 15:53:50 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *list, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *start;

	if (list == NULL || f == NULL)
		return (NULL);
	if (!(new = f(list)))
		return (NULL);
	start = new;
	while (list->next != NULL)
	{
		if (!(new->next = f(list->next)))
			return (NULL);
		list = list->next;
		new = new->next;
	}
	return (start);
}
