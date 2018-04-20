/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 10:56:53 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/20 21:28:39 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	print_tetriminos(t_triminos *tetriminos)
{
	int	x;
	int	y;

	y = 0;
	while (y < tetriminos->height)
	{
		x = 0;
		while (x < tetriminos->width)
		{
			ft_putchar(tetriminos->data[x][y] ? '#' : '.');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

void	print_tetris(t_list *tetris)
{
	t_list	*tmp;

	tmp = tetris;
	while (tmp != NULL)
	{
		print_tetriminos((t_triminos *)tmp->content);
		if ((tmp = tmp->next) != NULL)
			ft_putchar('\n');
	}
}

void	print_solution(int **tab, int size)
{
	int	x;
	int	y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (tab[x][y] == 0)
				ft_putchar('.');
			else
				ft_putchar(tab[x][y]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
	ft_putchar('\n');
}
