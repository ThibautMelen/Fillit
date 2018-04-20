/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 14:51:04 by jroussel          #+#    #+#             */
/*   Updated: 2018/04/20 13:59:28 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		open_file(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit_program(OPEN_FILE_ERROR);
	return (fd);
}

char	*read_file(int fd)
{
	char	*content;
	char	buff[BUFF_SIZE + 1];
	int		result;
	char	*tmp;

	if (!(content = ft_strnew(1)))
		exit_program(MALLOC_ERROR);
	while ((result = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[result] = '\0';
		tmp = content;
		if (!(content = ft_strjoin(tmp, buff)))
			exit_program(MALLOC_ERROR);
		free(tmp);
	}
	if (result == -1)
		exit_program(READ_FILE_ERROR);
	return (content);
}
