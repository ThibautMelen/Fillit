/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:43:46 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/05 15:06:31 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *str, void (*f)(char *))
{
	unsigned int i;

	if (str == NULL || f == NULL)
		return ;
	i = 0;
	while (str[i] != '\0')
		f(&str[i++]);
}
