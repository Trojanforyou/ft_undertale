/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:44:59 by msokolov          #+#    #+#             */
/*   Updated: 2025/04/23 18:05:09 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	wall_check(t_map *map_data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	
	map_data->hight = find_last(map_data->map);
	map_data->width = ft_strlen(map_data->map[0]);
	printf("w = %d\n", map_data->width);
	printf("H = %d\n", map_data->hight);
	while (i < map_data->hight)
	{
		if (map_data->map[i][0] != '1' || map_data->map[i][map_data->width - 1] != '1')
		{
			return(ft_printf("Invalid Map Structure\n"), 0);
		}
		i++;
	}
	while (j < map_data->width)
	{
		if (map_data->map[0][j] != '1' || map_data->map[map_data->hight - 1][j] != '1')
		{
			return(ft_printf("Invalid Map Structure\n"), 0);	
		}
		j++;
	}
	return (1);
}

int	title_and_wall(t_map *map_data)
{
	if (title_check(map_data))
		return (1);
	if (wall_check(map_data))
		return (1);
	return (0);
}
