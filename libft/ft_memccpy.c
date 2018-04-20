/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 20:37:03 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/05 09:47:46 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int chr, size_t size)
{
	while (size--)
	{
		*(t_byte *)dest++ = *(t_byte *)src;
		if (*(t_byte *)src++ == (t_byte)chr)
			return ((t_byte *)dest);
	}
	return (NULL);
}
