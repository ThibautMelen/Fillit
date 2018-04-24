/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 17:10:45 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/24 18:42:37 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** Definie la bonne longeur d'un tetriminos
*/

static void	set_width(t_triminos *tetri)
{
	int x;
	int y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (tetri->data[x][y] == '#')
				break ;
			y++;
		}
		if (y == 4)
		{
			tetri->width = x;
			break ;
		}
		x++;
	}
}

/*
** Definie la bonne hauteur d'un tetriminos
*/

static void	set_height(t_triminos *tetri)
{
	int	x;
	int	y;
	
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tetri->data[x][y] == '#')
				break ;
			x++;
		}
		if (x == 4)
		{
			tetri->height = y;
			break ;
		}
		y++;
	}
}

/*
** Deplace le tetriminos en haut a gauche
*/

static void	move_tetriminos(t_triminos *tetri, int x, int y)
{
	int	i;
	int	j;

	if (x + y == 0)
		return ;
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (tetri->data[i][j] == '#')
			{
				tetri->data[i - x][j - y] = tetri->data[i][j];
				tetri->data[i][j] = '.';
			}
			i++;
		}
		j++;
	}
}

/*
** Verifie si au moins un des coins du block(x, y) de 'tetri' est plein
*/

static int	check_corners(t_triminos *tetri, int x, int y)
{
	if (tetri->data[x + 1][y] == '#' && tetri->data[x][y + 1] == '#')
		return (1);
	if (x + 2 < 4 && tetri->data[x + 2][y] == '#'
		&& tetri->data[x][y + 1] == '#')
		return (1);
	if (y + 2 < 4 && tetri->data[x + 1][y] == '#'
		&& tetri->data[x][y + 2] == '#')
		return (1);
	return (0);
}

void		reduce_tetriminos(t_triminos *tetri)
{
	int	x;
	int	y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tetri->data[x][y] == '#')
				move_tetriminos(tetri, x, y);
			else if (x + 1 < 4 && check_corners(tetri, x, y))
				move_tetriminos(tetri, x, y);
			else
			{
				x++;
				continue ;
			}
			set_width(tetri);
			set_height(tetri);
			return ;
		}
		y++;
	}
}
