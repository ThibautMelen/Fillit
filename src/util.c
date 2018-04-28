/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 11:36:13 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/28 12:27:28 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		exit_program(int status)
{
	if (status < 0)
	{
		ft_putstr("error");
		ft_putchar('\n');
	}
	exit(status);
}

void		show_usage(const char *name)
{
	ft_putstr("usage: ");
	ft_putstr(name);
	ft_putendl(" {file}");
	exit_program(NO_ERROR);
}

t_point		new_point(int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

void		check_content(char *content, int i, int j)
{
	if (i % 5 == 4 && content[i + j] != '\n')
		exit_program(CONTENT_ERROR);
	if (i % 5 != 4 && !(content[i + j] == '.' || content[i + j] == '#'))
		exit_program(CONTENT_ERROR);
}

void		check_amount_sum(int amount, int sum)
{
	if (amount != 4)
		exit_program(CONTENT_ERROR);
	if (sum < 6)
		exit_program(CONTENT_ERROR);
}
