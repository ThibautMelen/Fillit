/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 11:15:03 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/20 22:44:28 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static t_triminos	*new_tetriminos(void)
{
	t_triminos	*tetriminos;
	int			**tab;
	int			i;

	i = 0;
	if (!(tab = (int **)malloc(4 * sizeof(*tab))))
		exit_program(MALLOC_ERROR);
	while (i < 4)
	{
		if (!(tab[i] = (int *)malloc(4 * sizeof(**tab))))
			exit_program(MALLOC_ERROR);
		i++;
	}
	if (!(tetriminos = (t_triminos *)malloc(sizeof(*tetriminos))))
		exit_program(MALLOC_ERROR);
	tetriminos->data = tab;
	tetriminos->width = 4;
	tetriminos->height = 4;
	return (tetriminos);
}

static void			fill_tetriminos(char *str, t_triminos *tetriminos)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i + j < 19)
	{
		tetriminos->data[i % 4][(i + j) / 5] = str[i + j] == '#';
		if ((i + j) % 5 == 3)
			j++;
		i++;
	}
	tidy_tetriminos(tetriminos);
	reduce_tetriminos(tetriminos);
}

t_list				*parse_tetris(t_list *list)
{
	t_list		*tetris;
	t_list		*tmp;
	int			i;
	t_triminos	*tetriminos;
	t_list		*new;

	tetris = NULL;
	tmp = list;
	i = 0;
	while (tmp != NULL)
	{
		tetriminos = new_tetriminos();
		fill_tetriminos((char *)tmp->content, tetriminos);
		new = ft_lstnew(tetriminos, sizeof(*tetriminos));
		new->ASCII = i + 'A';
		ft_lstpush(&tetris, new);
		free(tetriminos);
		tmp = tmp->next;
		i++;
	}
	ft_lstclear(&list);
	return (tetris);
}
