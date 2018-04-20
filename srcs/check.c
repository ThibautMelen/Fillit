/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 16:55:29 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/20 13:59:05 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int		check_size(int i, int start, char *content)
{
	while (i - start != 20)
	{
		if (content[i] == '\0')
			exit_program(CONTENT_ERROR);
		i++;
	}
	return (i);
}

static t_list	*check_struct(char *content)
{
	t_list	*list;
	int		start;
	int		i;
	char	*sub;

	list = NULL;
	i = 0;
	while (content[i] != '\0')
	{
		start = i;
		i = check_size(i, start, content);
		if (!(content[i - start - 1] == '\n' && (content[i - start] == '\n'
				|| content[i - start] == '\0')))
			exit_program(CONTENT_ERROR);
		sub = ft_strsub(content, start, i - start);
		ft_lstpush(&list, ft_lstnew(sub, i - start));
		free(sub);
		if (content[i] != '\0')
			i++;
	}
	free(content);
	return (list);
}

static int		sides_count(int x, char *str)
{
	int	sides[4];
	int i;
	int	count;

	sides[0] = -5;
	sides[1] = -1;
	sides[2] = 1;
	sides[3] = 5;
	i = 0;
	count = 0;
	while (i < 4)
	{
		if (x + sides[i] > -1 && x + sides[i] < 19 && !(x + sides[i] == 4 ||
				x + sides[i] == 9 || x + sides[i] == 14))
		{
			if (str[x + sides[i]] == '#')
				count++;
			else if (str[x + sides[i]] != '.')
				exit_program(CONTENT_ERROR);
		}
		i++;
	}
	return (count);
}

static void		check_list(t_list *list)
{
	int		i;
	int		amount;
	int		count;
	int		sum;
	t_list	*tmp;

	tmp = list;
	while (tmp != NULL)
	{
		i = -1;
		amount = 0;
		sum = 0;
		while (++i < 19)
		{
			if ((((char *)tmp->content))[i] == '#')
			{
				count = sides_count(i, (char *)tmp->content);
				if (count == 0)
					exit_program(CONTENT_ERROR);
				sum += count;
				amount++;
			}
		}
		tmp = tmp->next;
	}
}

t_list			*check_content(char *content)
{
	t_list	*list;

	if (content[0] == '\0')
		exit_program(CONTENT_ERROR);
	list = check_struct(content);
	check_list(list);
	return (list);
}
