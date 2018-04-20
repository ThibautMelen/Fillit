/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 10:46:02 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/12 10:46:38 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlower(const char *str)
{
	char	*new;
	int		i;

	new = ft_strnew(ft_strlen(str));
	i = 0;
	while (str[i] != '\0')
	{
		new[i] = ft_tolower(str[i]);
		i++;
	}
	return (new);
}
