/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 21:01:52 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/05 09:59:23 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	int		i;

	if ((t_byte *)dest < (t_byte *)src)
		ft_memcpy(dest, src, size);
	else if ((t_byte *)dest > (t_byte *)src)
	{
		i = size - 1;
		while (i >= 0)
		{
			((t_byte *)dest)[i] = ((t_byte *)src)[i];
			i--;
		}
	}
	return (dest);
}
