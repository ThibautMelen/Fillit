/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 11:36:13 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/24 15:28:47 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		exit_program(int status)
{
	if (status < 0)
	{
		ft_putstr("error (");
		ft_putnbr(status);
		ft_putchar(')');
		ft_putchar('\n');
	}
	exit(status);
}

void		show_usage(const char *name)
{
	ft_putstr("usage: ");
	ft_putstr(name);
	ft_putendl(" {file}");
	exit_program(NO_ERROR);
}
