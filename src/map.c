/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 18:53:07 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/28 11:45:41 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void **)&(map->data[i]));
		i++;
	}
	ft_memdel((void **)&(map->data));
	ft_memdel((void **)&map);
}

t_map	*map_new(int size)
{
	t_map	*map;
	int		i;
	int		j;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->size = size;
	map->data = (char **)ft_memalloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		map->data[i] = ft_strnew(size);
		j = 0;
		while (j < size)
		{
			map->data[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

int		place(t_triminos *tetri, t_map *map, int x, int y)
{
	int		i;
	int		j;

	j = 0;
	while (j < tetri->height)
	{
		i = 0;
		while (i < tetri->width)
		{
			if (tetri->data[i][j] == '#' && map->data[y + j][x + i] != '.')
				return (0);
			i++;
		}
		j++;
	}
	set_piece(tetri, map, new_point(x, y), tetri->value);
	return (1);
}

void	set_piece(t_triminos *tetri, t_map *map, t_point p, char c)
{
	int i;
	int j;

	j = 0;
	while (j < tetri->height)
	{
		i = 0;
		while (i < tetri->width)
		{
			if (tetri->data[i][j] == '#')
				map->data[p.y + j][p.x + i] = c;
			i++;
		}
		j++;
	}
}
