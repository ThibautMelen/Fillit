/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:23:31 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/05 10:36:51 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long	nbr;
	int					neg;

	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'
			|| *str == '\r' || *str == '\f')
		str++;
	if ((neg = (*str == '-')) || *str == '+')
		str++;
	nbr = 0;
	while (ft_isdigit(*str))
		nbr = (nbr * 10) + (*str++ - '0');
	if (nbr > 9223372036854775807)
		return (neg ? 0 : -1);
	return (neg ? -(int)nbr : (int)nbr);
}
