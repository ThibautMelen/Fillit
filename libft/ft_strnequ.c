/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:39:27 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/05 10:48:57 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(const char *str1, const char *str2, size_t size)
{
	if (str1 == NULL || str2 == NULL)
		return (0);
	return (!ft_strncmp(str1, str2, size));
}
