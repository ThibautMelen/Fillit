/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:13:53 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/11 18:15:57 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	clear(void *content, size_t size)
{
	if (content != NULL && !!size)
		free(content);
}

void		ft_lstclear(t_list **plist)
{
	ft_lstdel(plist, &clear);
}
