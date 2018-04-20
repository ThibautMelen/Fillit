/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:47:16 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/11 18:12:17 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddi(t_list **plist, t_list *new, int index)
{
	t_list	*tmp;
	int		i;

	if (plist == NULL || new == NULL || index < 0)
		return ;
	if (index == 0)
	{
		ft_lstadd(plist, new);
		return ;
	}
	tmp = *plist;
	i = 0;
	while (tmp != NULL)
	{
		if (i + 1 == index)
		{
			new->next = tmp->next;
			tmp->next = new;
			return ;
		}
		tmp = tmp->next;
		i++;
	}
}
