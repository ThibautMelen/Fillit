/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 14:34:16 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/28 11:29:59 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** Remplie le tetriminos avec le contnue de 'content'
*/

static void			fill_tetriminos(char *content, t_triminos *tetri)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (content[i + j] != '\0')
	{
		tetri->data[i % 4][i / 4] = content[i + j];
		i++;
		if (i % 4 == 0)
			j++;
	}
}

/*
** Cree un nouveau tetriminos
*/

static t_triminos	*new_tetriminos(char *content, int index)
{
	t_triminos	*tetri;
	char		**data;
	int			i;

	i = 0;
	if (!(data = (char **)malloc(4 * sizeof(*data))))
		exit_program(MALLOC_ERROR);
	while (i < 4)
	{
		if (!(data[i] = (char *)malloc(4 * sizeof(**data))))
			exit_program(MALLOC_ERROR);
		i++;
	}
	if (!(tetri = (t_triminos *)malloc(sizeof(*tetri))))
		exit_program(MALLOC_ERROR);
	tetri->data = data;
	tetri->width = 4;
	tetri->height = 4;
	tetri->value = index + 'A';
	fill_tetriminos(content, tetri);
	reduce_tetriminos(tetri);
	return (tetri);
}

t_list				*parse(t_list *list)
{
	t_list		*tetris;
	int			i;
	t_triminos	*tetri;

	tetris = NULL;
	i = 0;
	while (list != NULL)
	{
		tetri = new_tetriminos((char *)list->content, i++);
		ft_lstpush(&tetris, ft_lstnew(tetri, sizeof(*tetri)));
		ft_memdel((void **)&tetri);
		list = list->next;
	}
	ft_lstclear(&list);
	return (tetris);
}
