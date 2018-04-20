/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tidy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 22:42:57 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/20 22:44:01 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static void			move_tetriminos(t_triminos *tetriminos, int x, int y)
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
			if (tetriminos->data[i][j] == 1)
			{
				tetriminos->data[i - x][j - y] = tetriminos->data[i][j];
				tetriminos->data[i][j] = 0;
			}
			i++;
		}
		j++;
	}
}

static int			check_corners(t_triminos *tetriminos, int x, int y)
{
	if (tetriminos->data[x + 1][y] && tetriminos->data[x][y + 1])
		return (1);
	if (x + 2 < 4 && tetriminos->data[x + 2][y] && tetriminos->data[x][y + 1])
		return (1);
	if (y + 2 < 4 && tetriminos->data[x + 1][y] && tetriminos->data[x][y + 2])
		return (1);
	return (0);
}

void				tidy_tetriminos(t_triminos *tetriminos)
{
	int	x;
	int	y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tetriminos->data[x][y] == 1)
				move_tetriminos(tetriminos, x, y);
			else if (x + 1 < 4 && check_corners(tetriminos, x, y))
				move_tetriminos(tetriminos, x, y);
			else
			{
				x++;
				continue ;
			}
			return ;
		}
		y++;
	}
}
