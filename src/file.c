/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 11:33:39 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/24 14:33:43 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** Verifie si le contenu de 'buff' est correcte
*/

static void	check_buff(const char *buff)
{
	int i;

	while (buff[i] != '\0')
	{
		if (!(buff[i] == '#' || buff[i] == '.' || buff[i] == '\n'))
			exit_program(BUFF_ERROR);
		i++;
	}
	if (i < 20)
		exit_program(BUFF_ERROR);
}

int			open_file(char *path)
{
	int fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit_program(OPEN_FILE_ERROR);
	return (fd);
}

char		*read_file(int fd)
{
	char	*content;
	char	*buff = malloc(BUFF_SIZE + 1); // Change : buff[BUFF_SIZE + 1];
	int		result;
	char	*tmp;

	if (!(content = ft_strnew(1)))
		exit_program(MALLOC_ERROR);
	while ((result = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[result] = '\0';
		check_buff(buff);
		tmp = content;
		if (!(content = ft_strjoin(tmp, buff)))
			exit_program(MALLOC_ERROR);
		free(tmp);
	}
	if (result == -1)
		exit_program(READ_FILE_ERROR);
	return (content);
}
