/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 10:24:15 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/12 10:50:45 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(const char *str)
{
	char	*new;
	int		i;

	if (str == NULL)
		return (NULL);
	new = ft_strnew(ft_strlen(str));
	new[0] = ft_toupper(str[0]);
	i = 1;
	while (str[i] != '\0')
	{
		if (!ft_isalnum(str[i - 1]) && ft_isalnum(str[i]))
			new[i] = ft_toupper(str[i]);
		else
			new[i] = ft_tolower(str[i]);
		i++;
	}
	return (new);
}
