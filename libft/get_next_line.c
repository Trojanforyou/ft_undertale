/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:51:28 by msokolov          #+#    #+#             */
/*   Updated: 2025/03/04 20:50:51 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*clean_storage(char *storage)
{
	char	*new_storage;
	char	*ptr;
	int		len;

	ptr = ft_strchr_next(storage, '\n');
	if (!ptr)
		return (free(storage), storage = NULL, new_storage = NULL);
	else
		len = (ptr - storage) + 1;
	if (!storage[len])
		return (free(storage), storage = NULL);
	new_storage = ft_substr_next(storage, len, ft_strlen_next(storage) - len);
	(free(storage), storage = NULL);
	if (!new_storage)
		return (NULL);
	return (new_storage);
}

static char	*new_line(char *storage)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = ft_strchr_next(storage, '\n');
	len = (ptr - storage) + 1;
	line = ft_substr_next(storage, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*read_buffer(int fd, char *storage)
{
	int		rid;
	char	*buffer;

	rid = 1;
	buffer = malloc((BUFFER_SIZE + 1) * 1);
	if (!buffer)
		return (free(storage), storage = NULL, NULL);
	buffer[0] = '\0';
	while (rid > 0 && !ft_strchr_next(buffer, '\n'))
	{
		rid = read (fd, buffer, BUFFER_SIZE);
		if (rid > 0)
		{
			buffer[rid] = '\0';
			storage = ft_strjoin_next(storage, buffer);
		}
	}
	free(buffer);
	if (rid == -1)
		return (free(storage), storage = NULL, NULL);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0)
		return (NULL);
	if ((storage && !ft_strchr_next(storage, '\n')) || !storage)
		storage = read_buffer (fd, storage);
	if (!storage)
		return (NULL);
	line = new_line(storage);
	if (!line)
		return (free(storage), storage = NULL, NULL);
	storage = clean_storage(storage);
	return (line);
}
