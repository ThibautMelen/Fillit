/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 12:13:28 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/28 11:41:59 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** Compte le nombre de "\n\n"
*/

static int		newline_count(char *content)
{
	int i;
	int	count;

	i = 1;
	count = 0;
	while (content[i] != '\0')
	{
		if (content[i - 1] == '\n' && content[i] == '\n')
			count++;
		i++;
	}
	return (count + 1);
}

/*
** Verifie si la structure est correcte
*/

static t_list	*check_struct(char *content)
{
	t_list	*list;
	int		i;
	int		j;
	char	*tmp;

	list = NULL;
	i = 0;
	j = 0;
	while (content[i] != '\0')
	{
		check_content(content, i, j);
		if (++i == 20)
		{
			tmp = ft_strsub(content, j, 20);
			ft_lstpush(&list, ft_lstnew(tmp, 20));
			free(tmp);
			if (content[i + j] == '\0')
				break ;
			if (content[i + j] != '\n')
				exit_program(CONTENT_ERROR);
			i = 0;
			j += 21;
		}
	}
	return (list);
}

/*
** Compte le nombre de '#' autour de x
*/

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

/*
** Verifie si la liste cree par check_struc est correcte
*/

static void		check_list(t_list *list)
{
	int		i;
	int		amount;
	int		count;
	int		sum;

	while (list != NULL)
	{
		i = -1;
		amount = 0;
		sum = 0;
		while (++i < 19)
		{
			if ((((char *)list->content))[i] == '#')
			{
				count = sides_count(i, (char *)list->content);
				if (count == 0)
					exit_program(CONTENT_ERROR);
				sum += count;
				amount++;
			}
		}
		if (amount != 4)
			exit_program(CONTENT_ERROR);
		list = list->next;
	}
}

t_list			*check(char *content)
{
	int		count;
	t_list	*list;

	count = newline_count(content);
	if ((count * 20 + (count - 1)) != ft_strlen(content))
		exit_program(CONTENT_ERROR);
	list = check_struct(content);
	free(content);
	check_list(list);
	return (list);
}
