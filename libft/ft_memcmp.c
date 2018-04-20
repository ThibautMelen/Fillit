/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 13:22:55 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/05 10:02:33 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *mem1, const void *mem2, size_t size)
{
	while (size--)
	{
		if (*(t_byte *)mem1 != *(t_byte *)mem2)
			return (*(t_byte *)mem1 - *(t_byte *)mem2);
		mem1++;
		mem2++;
	}
	return (0);
}
