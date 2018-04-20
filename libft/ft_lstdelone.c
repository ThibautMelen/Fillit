/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:52:05 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/05 13:24:32 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **plist, void (*del)(void *, size_t))
{
	if (plist == NULL)
		return ;
	del((*plist)->content, (*plist)->content_size);
	free(*plist);
	*plist = NULL;
}
