/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 18:43:31 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/24 19:33:29 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** Implementation du backtracking
*/

static int	solve_map(t_map *map, t_list *list)
{
	int			x;
	int			y;
	t_triminos	*tetri;

	if (list == NULL)
		return (1);
	y = 0;
	tetri = (t_triminos *)(list->content);
	while (y < map->size - tetri->height + 1)
	{
		x = 0;
		while (x < map->size - tetri->width + 1)
		{
			if (place(tetri, map, x, y))
			{
				if (solve_map(map, list->next))
					return (1);
				else
					set_piece(tetri, map, x, y, '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}

/*
** Calcule de la taille de la map
*/

static int	map_size(int n)
{
	int size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

t_map		*solve(t_list *list)
{
	t_map	*map;
	int		size;

	size = map_size(ft_lstlen(list) * 4);
	map = map_new(size);
	while (!solve_map(map, list))
	{
		size++;
		free_map(map);
		map = map_new(size);
	}
	return (map);
}
