/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 13:14:20 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/05 13:46:10 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **plist, void (*del)(void *, size_t))
{
	t_list	*next;

	while (*plist != NULL)
	{
		next = (*plist)->next;
		ft_lstdelone(plist, del);
		*plist = next;
	}
}
