/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 10:49:17 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/05 10:15:36 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *search)
{
	int size;
	int i;
	int j;

	size = ft_strlen(search);
	if (size == 0)
		return ((char *)str);
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (search[j] == str[i + j])
		{
			if (j == size - 1)
				return ((char *)(str + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
