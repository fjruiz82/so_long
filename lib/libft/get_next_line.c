/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:51:51 by fruiz-ca          #+#    #+#             */
/*   Updated: 2023/05/30 11:25:18 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BUFFER_SIZE 512

char	*get_until(char **buffer, int until)
{
	char	*line;
	char	*n_ptr;
	char	*aux_buffer;

	n_ptr = ft_strchr(*buffer, until);
	if (!n_ptr)
		return (0);
	line = ft_substr(*buffer, 0, n_ptr - *buffer + 1);
	if (!line)
		return (0);
	aux_buffer = ft_substr(*buffer, n_ptr - *buffer + 1,
			ft_strlen_gnl(*buffer) - (n_ptr - *buffer));
	free(*buffer);
	if (!aux_buffer)
		return (0);
	*buffer = aux_buffer;
	return (line);
}

char	*read_and_find(int fd, char **buffer,
		char *buffer_read, ssize_t *bytes_read)
{
	char	*line;
	char	*buffer_aux;

	*bytes_read = read(fd, buffer_read, BUFFER_SIZE);
	if (*bytes_read == -1)
		return (0);
	buffer_aux = ft_strjoin_gnl(*buffer, buffer_read);
	if (!buffer_aux)
		return (0);
	free(*buffer);
	*buffer = buffer_aux;
	ft_bzero(buffer_read, BUFFER_SIZE);
	line = get_until(buffer, '\n');
	return (line);
}

char	*read_line(int fd, char **buffer)
{
	char	*buffer_read;
	char	*line;
	ssize_t	bytes_read;

	bytes_read = BUFFER_SIZE;
	buffer_read = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	line = 0;
	if (!buffer_read)
		return (0);
	while (bytes_read == BUFFER_SIZE && !line)
		line = read_and_find(fd, buffer, buffer_read, &bytes_read);
	free(buffer_read);
	if (*buffer && !**buffer)
	{
		free(*buffer);
		*buffer = 0;
	}
	if (!line && *buffer && **buffer)
	{
		line = ft_substr_gnl(*buffer, 0, ft_strlen(*buffer));
		free(*buffer);
		*buffer = 0;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffers[512];
	char		*line;

	if (fd < 0)
		return (0);
	line = read_line(fd, buffers + fd);
	return (line);
}
