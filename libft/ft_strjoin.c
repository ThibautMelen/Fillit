/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:56:01 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/05 10:46:43 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *str1, const char *str2)
{
	size_t	len;
	char	*new_str;

	if (str1 == NULL || str2 == NULL)
		return (NULL);
	len = ft_strlen(str1) + ft_strlen(str2);
	if (!(new_str = ft_strnew(len)))
		return (NULL);
	while (*str1 != '\0')
		*new_str++ = *str1++;
	while (*str2 != '\0')
		*new_str++ = *str2++;
	*new_str = '\0';
	return (new_str -= len);
}
