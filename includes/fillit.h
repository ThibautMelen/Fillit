/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 11:20:34 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/28 11:49:14 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFF_SIZE 42

# define NO_ERROR 0
# define OPEN_FILE_ERROR -1
# define READ_FILE_ERROR -2
# define BUFF_ERROR -3
# define CONTENT_ERROR -4
# define MALLOC_ERROR -42

# include <stdio.h>

typedef struct	s_triminos
{
	char	**data;
	int		width;
	int		height;
	char	value;
}				t_triminos;
typedef struct	s_map
{
	char	**data;
	int		size;
}				t_map;
typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

/*
** Ouvre le fichier 'path'
*/
int				open_file(char *path);
/*
** Lit le contenue du ficiher lie a 'fd'
*/
char			*read_file(int fd);
/*
** Quite le programme avec comme code d'erreur 'status'
*/
void			exit_program(int status);
/*
** Affiche l'usage du programme
*/
void			show_usage(const char *name);
/*
** Cree un nouveau t_point et socke x et y dedant
*/
t_point			new_point(int x, int y);
/*
** Verifie le contenue de du char[i + j] de content
*/
void			check_content(char *content, int i, int y);
/*
** Verifie si la structure de 'content' est correcte
*/
t_list			*check(char *content);
/*
** Transforme une liste de string en liste de t_triminos
*/
t_list			*parse(t_list *list);
/*
** Deplace le tetriminos en haut a gauche et reduit sa taille
*/
void			reduce_tetriminos(t_triminos *tetri);
/*
** Free l'ancienne map
*/
void			free_map(t_map *map);
/*
** Cree une nouvelle map de taille 'size'
*/
t_map			*map_new(int size);
/*
** Verifie et place 'tetri' sur la map a la position(x, y)
*/
int				place(t_triminos *tetri, t_map *map, int x, int y);
/*
** Comme 'place()' mais avec un charactere 'c'
*/
void			set_piece(t_triminos *tetri, t_map *map, t_point p, char c);
/*
** Place tous les tetriminos dans 'list' dans le plus petit carre
*/
t_map			*solve(t_list *list);
/*
** Affiche la map resolue
*/
void			print_map(t_map *map);

#endif
