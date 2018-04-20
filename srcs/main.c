/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 11:18:36 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/20 17:49:19 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"


#include <stdio.h>
size_t	ft_lst_size(t_list *list);
void		ft_list_print(t_list *tetrimos);
int		size_map_max(t_list *tetris);
int **new_map(int size);
int** flt_resolver(t_list *tetris, int *map_size);

//////////////////////////////
// /////// AFFICAGE /////// //
//////////////////////////////

size_t	ft_lst_size(t_list *list)
{
	size_t i;

	i = 0;
	while (list != NULL)
	{
		list = list->next;
		i++;
	}
	return (i);
}

void		ft_list_print(t_list *tetrimos)
{
	int x;
	int y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			printf("%d", ((int **)tetrimos->content)[x][y]);
			x++;
		}
		printf("\n");
		y++;
	}

	printf("%c : ", tetrimos->ASCII);
	printf("%zu\n", tetrimos->ASCII);

}

//////////////////////////////
// /////// GESTION MAP /////// //
//////////////////////////////

int	**map_cpy(int **map, int size)
{
	int	i;
	int j;
	int	**map_save;

	if (!(map_save = (int **)malloc(sizeof(int *) * (size + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (j < size)
	{
		if (!(map_save[j] = (int *)malloc(sizeof(int) * (size + 1))))
			return (NULL);
		while (i < size)
		{
			map_save[j][i] = map[j][i];
			i++;
		}
		i = 0;
		j++;
	}
	map_save[j] = NULL;
	return (map_save);
}

int **new_map(int size)
{
	int **map;
	int i;
	int j;

	i = 0;
	j = 0;

	if (!(map = (int **)malloc(sizeof(int *) * (size + 1))))
		return (NULL);
	while (j < size)
	{
		if (!(map[j] = (int *)malloc(sizeof(int) * (size + 1))))
			return (NULL);
		while (i < size)
		{
			map[j][i] = 0;
			i++;
		}
		i = 0;
		j++;
	}
	map[j] = NULL;
	return (map);
}

int		size_map_max(t_list *tetris)
{
	int size;
	int nb_lego;

	size = 2;
	nb_lego = (int)ft_lst_size(tetris) * 4;
	while ((size * size) < nb_lego)
		size++;
	return (size);
}

//////////////////////////////
// PLACING TETROMINOS LEGO //
//////////////////////////////

int its_possible_place(int **map, t_list *tetris, int x, int y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (map[x + i][y + j] != 0 && ((int**)tetris->content)[i][j] != 0)
				return (FALSE);
			j++;
		}
		j = 0;
		i++;
	}
	return (TRUE);
}

int place_lego_on_map(int **map, t_list *tetris, int x, int y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	// tetris->content[i]
	while (i < 4)
	{
		while (j < 4)
		{
			if (((int **)tetris->content)[i][j] == ELEMENT)
				map[x + i][y + j] = tetris->ASCII;
			j++;
		}
		j = 0;
		i++;
	}
	return (TRUE);
}

int place_lego(int **map, int map_size_max, t_list *tetris, int *x, int *y)
{
	while(*y < map_size_max)
	{
		while (*x < map_size_max)
		{
			if (its_possible_place(map, tetris, *x, *y) == TRUE)
					return (place_lego_on_map(map, tetris, *x, *y));
			(*x)++;
		}
		(*x) = 0;
		(*y)++;
	}
	return (FALSE);
}


//////////////////////////////
// /////// COEUR ALGO /////// //
//////////////////////////////

int map_resolver(int **map, int map_size_max, t_list *tetris)
{
	int x;
	int y;
	int **tmp_map;

	x = 0;
	y = 0;
	if (tetris == NULL)//condition d'arret de la recursive (plus de lego/tetrominos)
		return (1);
	tmp_map = map_cpy(map, map_size_max); //On copie la map et on la met dans un tmp
	/* TO DEL ->*/print_solution(tmp_map, map_size_max);
	while (place_lego(map, map_size_max, tetris, &x, &y) != FALSE) //tant qu'on peut placer les tetrominos
	{
		if(map_resolver(map, map_size_max, tetris->next) == TRUE)
			return (TRUE);
		x++; //recursive++ | on travaille les acbsisses +1
		map = tmp_map;
	}
	return (FALSE);
}

int** flt_resolver(t_list *tetris, int *map_size_max)
{
	int **final_map;

	*map_size_max = size_map_max(tetris); //calcul le carre max (minimum place possible)
	// ft_putnbr(*map_size);
	// ft_putstr("\n\n");

	final_map = new_map(*map_size_max);
	while(map_resolver(final_map, *map_size_max, tetris) != TRUE)
	{
		//ancienne map a FREE !
		final_map = new_map(*map_size_max);
		//recursive place
		(*map_size_max)++; //augmente la taille de la map
	}
	return (final_map);
}

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

	int map_size;
	int **map;

	map_size = 0;
	map = flt_resolver(tetris, &map_size);
	ft_putstr("FINAL : \n");
	print_solution(map, map_size);
	// print_tetris(tetris);

//	ft_list_print(tetris->next->next);

	return (NO_ERROR);
}
