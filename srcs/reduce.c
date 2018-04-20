/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 21:44:55 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/20 22:46:50 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static void	set_width(t_triminos *tetriminos)
{
	int x;
	int y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (tetriminos->data[x][y])
				break ;
			y++;
		}
		if (y == 4)
		{
			tetriminos->width = x;
			break ;
		}
		x++;
	}
}

static void	set_height(t_triminos *tetriminos)
{
	int	x;
	int	y;
	
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tetriminos->data[x][y])
				break ;
			x++;
		}
		if (x == 4)
		{
			tetriminos->height = y;
			break ;
		}
		y++;
	}
}

void		reduce_tetriminos(t_triminos *tetriminos)
{
	set_width(tetriminos);
	set_height(tetriminos);
}
