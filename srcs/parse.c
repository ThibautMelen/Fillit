/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 11:15:03 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/20 18:05:01 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static void	move_tetrimos(int **tetrimos, int x, int y)
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
			if (tetrimos[i][j] == 1)
			{
				tetrimos[i - x][j - y] = tetrimos[i][j];
				tetrimos[i][j] = 0;
			}
			i++;
		}
		j++;
	}
}

static int	check_corners(int **tetrimos, int x, int y)
{
	if (tetrimos[x + 1][y] && tetrimos[x][y + 1])
		return (1);
	if (x + 2 < 4 && tetrimos[x + 2][y] && tetrimos[x][y + 1])
		return (1);
	if (y + 2 < 4 && tetrimos[x + 1][y] && tetrimos[x][y + 2])
		return (1);
	return (0);
}

static void	tidy_tetrimos(int **tetrimos)
{
	int	x;
	int	y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tetrimos[x][y] == 1)
				move_tetrimos(tetrimos, x, y);
			else if (x + 1 < 4 && check_corners(tetrimos, x, y))
				move_tetrimos(tetrimos, x, y);
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

static void	fill_tetrimos(char *str, int **tetrimos)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i + j < 19)
	{
		tetrimos[i % 4][(i + j) / 5] = str[i + j] == '#';
		if ((i + j) % 5 == 3)
			j++;
		i++;
	}
	tidy_tetrimos(tetrimos);
}

t_list		*parse_tetris(t_list *list)
{
	t_list	*tetris;
	t_list	*tmp;
	int		i;
	int		**tetrimos;
	t_list	*new;

	tetris = NULL;
	tmp = list;
	i = 0;
	while (tmp != NULL)
	{
		tetrimos = new_tetrimos();
		fill_tetrimos((char *)tmp->content, tetrimos);
		new = ft_lstnew(tetrimos, sizeof(*tetrimos) * sizeof(**tetrimos));
		new->ASCII = i + 'A';
		ft_lstpush(&tetris, new);
		free(tetrimos);
		tmp = tmp->next;
		i++;
	}
	ft_lstclear(&list);
	return (tetris);
}
