/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 14:19:13 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/05 15:51:19 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int nbr)
{
	int len;

	len = (nbr < 0) ? 1 : 0;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int nbr)
{
	char	*str;
	int		len;
	int		neg;

	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	if (nbr == 0)
		return (ft_strdup("0"));
	len = ft_nbrlen(nbr);
	if ((neg = (nbr < 0)))
		nbr = -nbr;
	if (!(str = ft_strnew(len)))
		return (NULL);
	str += len - 1;
	while (nbr)
	{
		*str-- = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (neg)
		*str-- = '-';
	return (str + 1);
}
