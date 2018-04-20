/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 22:17:50 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/04 17:29:41 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *mem, int chr, size_t size)
{
	while (size--)
	{
		if (*(t_byte *)mem == (t_byte)chr)
			return ((void *)mem);
		mem++;
	}
	return (NULL);
}
