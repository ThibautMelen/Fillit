/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 11:18:36 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/20 21:44:15 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

//////////////////////////////
// /////// MAIN /////// //
//////////////////////////////

int	main(int argc, char **argv)
{
	/////////////////////
	if (argc != 2)
		show_usage(argv[0]);
	int fd = open_file(argv[1]); // OK
	char *content = read_file(fd); // OK
	t_list *list = check_content(content); // OK. !! 'content' est free !!
	t_list *tetris = parse_tetris(list); // OK !! 'list' est free !!
	/////////////////////

	print_tetris(tetris);

	// int map_size;
	// int **map;

	// map_size = 0;
	// map = flt_resolver(tetris, &map_size);
	// ft_putstr("FINAL : \n");
	// print_solution(map, map_size);
	// print_tetris(tetris);

//	ft_list_print(tetris->next->next);

	return (NO_ERROR);
}
