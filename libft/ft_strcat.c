/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:34:13 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/04 10:46:04 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *str1, const char *str2)
{
	size_t i;

	i = ft_strlen(str1);
	while (*str2 != '\0')
		str1[i++] = *str2++;
	str1[i] = '\0';
	return (str1);
}
