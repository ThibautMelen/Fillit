/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:47:30 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/05 10:46:23 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *str, unsigned int start, size_t size)
{
	char			*new_str;
	unsigned int	i;

	if (str == NULL)
		return (NULL);
	if (!(new_str = ft_strnew(size)))
		return (NULL);
	i = -1;
	while (++i < size)
		new_str[i] = str[start + i];
	new_str[i] = '\0';
	return (new_str);
}
