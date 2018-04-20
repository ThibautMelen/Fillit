/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 11:26:33 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/20 18:05:54 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	exit_program(int status)
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

void	show_usage(const char *name)
{
	ft_putstr("usage: ");
	ft_putstr(name);
	ft_putendl(" {file}");
	exit_program(NO_ERROR);
}

int		**new_tetrimos(void)
{
	int		**tetrimos;
	int		i;

	i = 0;
	if (!(tetrimos = (int **)malloc(4 * sizeof(*tetrimos))))
		exit_program(MALLOC_ERROR);
	while (i < 4)
	{
		if (!(tetrimos[i] = (int *)malloc(4 * sizeof(**tetrimos))))
			exit_program(MALLOC_ERROR);
		i++;
	}
	return (tetrimos);
}
