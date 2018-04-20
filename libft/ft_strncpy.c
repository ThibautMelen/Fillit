/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 18:55:12 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/03 17:09:15 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t size)
{
	size_t i;

	i = 0;
	while (i++ < size && *src != '\0')
		*dest++ = *src++;
	i--;
	while (i++ < size)
		*dest++ = '\0';
	return (dest -= size);
}
