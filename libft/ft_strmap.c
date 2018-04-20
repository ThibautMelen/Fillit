/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:58:24 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/05 10:44:51 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *str, char (*f)(char))
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
		new_str[i] = f(str[i]);
		i++;
	}
	return (new_str);
}
