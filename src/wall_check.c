/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:44:59 by msokolov          #+#    #+#             */
/*   Updated: 2025/05/10 19:34:35 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	wall_check(t_map *map_data)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	map_data->hight = find_last(map_data->map);
	map_data->width = ft_strlen(map_data->map[0]);
	if (!map_data->width || !map_data->hight)
		return (0);
	while (++i < map_data->hight)
	{
		if (map_data->map[i][0] != WALL
			|| map_data->map[i][map_data->width - 1] != WALL)
			return (ft_printf("Invalid Map Structure\n"), 0);
	}
	while (++j < map_data->width)
	{
		if (map_data->map[0][j] != WALL
			|| map_data->map[map_data->hight - 1][j] != WALL)
			return (ft_printf ("Invalid Map Structure\n"), 0);
	}
	return (1);
}
