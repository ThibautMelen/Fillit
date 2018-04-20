/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 10:56:53 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/20 17:49:11 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	print_tetrimos(int **tetrimos)
{
	int	x;
	int	y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			ft_putchar(tetrimos[x][y] ? '#' : '.');
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
		print_tetrimos((int **)tmp->content);
		if ((tmp = tmp->next) != NULL)
			ft_putchar('\n');
	}
}

void	print_solution(int **tab, int map_size)
{
	int	x;
	int	y;

	y = 0;
	while (y < map_size)
	{
		x = 0;
		while (x < map_size)
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
