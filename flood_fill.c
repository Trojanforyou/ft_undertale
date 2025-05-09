/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:00:23 by msokolov          #+#    #+#             */
/*   Updated: 2025/03/12 19:32:06 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	flood_fill(t_map *map_data, int y, int x)
{
	if (x < 0 || y < 0 || x >= map_data->height || y >= map_data->width
	 || map_data->map_copy[y][x] == '1' || map_data->map_copy[x][y] == 'X')
		return ;
	if (map_data->map_copy[y][x] == 'E')
		map_data->map_copy[y][x] = 'X';
	else
	{
		map_data->map_copy[y][x] = 'X';
		flood_fill(map_data, x + 1, y);
		flood_fill(map_data, x - 1, x);
		flood_fill(map_data, x, y + 1);
		flood_fill(map_data, x, y - 1);
	}
}
int	check_flood(t_map *map_data)
{
	int	y;
	int	x;

	y = 0;
	while(map_data->map_copy[y])
	{
		x = 0;
		while (map_data->map_copy[y][x])
		{
			if (map_data->map_copy[y][x] == 'C' || map_data->map_copy[y][x] == 'E')
				return (ft_printf("Invalid Map Flood\n"), 0);
			x++;
		}
		y++;
	}
	return (1);
}
