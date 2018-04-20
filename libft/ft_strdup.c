/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 18:30:44 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/05 15:13:44 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*newstr;

	len = ft_strlen(str) + 1;
	if (!(newstr = (char *)malloc(len * sizeof(*str))))
		return (NULL);
	ft_memcpy(newstr, str, len);
	return (newstr);
}
