/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 11:20:34 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/20 18:05:34 by jroussel         ###   ########.fr       */
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

# include <stdio.h> // !!!!!

# define BUFF_SIZE 42
# define ASCII content_size

# define TRUE 1
# define FALSE 0

# define ELEMENT 1

# define NO_ERROR 0
# define OPEN_FILE_ERROR -1
# define READ_FILE_ERROR -2
# define CONTENT_ERROR -3
# define MALLOC_ERROR -42

/*
** Util
*/
void	exit_program(int status);
void	show_usage(const char *name);
int		**new_tetrimos(void);

/*
** File
*/
int		open_file(const char *path);
char	*read_file(int fd);

/*
** Check
*/
t_list	*check_content(char *content);

/*
** Parse
*/
t_list	*parse_tetris(t_list *list);

/*
** Print
*/
void	print_tetrimos(int **tetrimos);
void	print_tetris(t_list *tetris);
void	print_solution(int **tetris, int map_size);

#endif
