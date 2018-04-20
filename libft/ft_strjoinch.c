/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 10:12:32 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/12 10:15:10 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinch(const char *str, char chr)
{
	size_t	len;
	char	*new_str;

	if (str == NULL)
		return (NULL);
	len = ft_strlen(str) + 1;
	if (!(new_str = ft_strnew(len)))
		return (NULL);
	while (*str != '\0')
		*new_str++ = *str++;
	*new_str++ = chr;
	*new_str = '\0';
	return (new_str -= len);
}
