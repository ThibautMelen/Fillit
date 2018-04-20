/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:29:17 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/05 10:44:44 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *str, char (*f)(unsigned int, char))
{
	char			*new_str;
	unsigned int	i;

	if (str == NULL)
		return (NULL);
	if (!(new_str = ft_strnew(ft_strlen(str))))
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		new_str[i] = f(i, str[i]);
		i++;
	}
	return (new_str);
}
