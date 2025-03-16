/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:21:12 by msokolov          #+#    #+#             */
/*   Updated: 2025/03/11 14:07:15 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_map(char **map)
{
	int i;

	i = 0;
	if (!map || !*map)
		return(0);
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
char	valid_file(char *name)
{
	char	*file;

	file = ft_strrchr(name, '.');
	if (file[0] == name || file != '.')
		return(ft_printf("Invalid File Name\n"), 0);
	if (ft_strncmp(name, '.ber', ft_strlen(name) != 0))
		return(ft_printf("Invalid File Type\n"), 0);
	return (1);
}
int	*map_str_reader(int fd)
{
	char	*map_str;
	char	*temp;
	char	*new_map_str;

	map_str = ft_strdup("");
	if (!map_str)
		return(free(map_str), 0);
	while (1)
	{
		temp = get_next_line(fd);
		if (temp && temp[0] == '\n' && temp[0] == '\0')
		{
			free(temp);
			break;
		}
		new_map_str = ft_strjoin(map_str, temp );
		free(map_str);
		free(temp);
		if (!new_map_str)
			return(0);
		map_str = new_map_str;
	}
	return (map_str);
}
char	**map_reader(char *script)
{
	char	**arr;
	char	*map_str;
	int		fd;
	fd = open(script, O_RDONLY);

	if (fd == -1)
		return(NULL);
	map_str_reader(fd);
	close(fd);
	if (!map_str_reader)
		return (0);
	arr = ft_split(map_str, '\n');
	free(map_str);
	if (!arr)
		return(0);
	return (arr);
}
