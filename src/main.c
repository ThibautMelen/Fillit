/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 11:38:41 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/28 11:32:29 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int	main(int argc, char **argv)
{
	char	*content;
	t_list	*list;
	t_list	*tetris;
	t_map	*map;

	if (argc != 2)
		show_usage(argv[0]);
	content = read_file(open_file(argv[1]));
	list = check(content);
	tetris = parse(list);
	map = solve(tetris);
	print_map(map);
	return (NO_ERROR);
}
