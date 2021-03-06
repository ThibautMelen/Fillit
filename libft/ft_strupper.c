/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 10:41:45 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/12 10:43:26 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strupper(const char *str)
{
	char	*new;
	int		i;

	new = ft_strnew(ft_strlen(str));
	i = 0;
	while (str[i] != '\0')
	{
		new[i] = ft_toupper(str[i]);
		i++;
	}
	return (new);
}
