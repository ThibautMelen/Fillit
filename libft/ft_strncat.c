/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:54:49 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/04 10:46:12 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *str1, const char *str2, size_t size)
{
	size_t len;
	size_t i;

	len = ft_strlen(str1);
	i = 0;
	while (*str2 != '\0' && i < size)
		str1[len + i++] = *str2++;
	str1[len + i] = '\0';
	return (str1);
}
