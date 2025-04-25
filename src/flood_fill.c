/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:54:30 by msokolov          #+#    #+#             */
/*   Updated: 2025/04/04 15:54:30 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void   flood_fill(t_map *map_data, int y, int x)
{
	if (!map_data || !map_data->map_copy)
		return ;
	// printf("x=%d\n y=%d\n", x, y);
	if (x < 0 || y < 0 || x >= map_data->width || y >= map_data->hight )
		return ;
	if (map_data->map_copy[y][x] == '1' || map_data->map_copy[y][x] == 'X')
		return ;
	if (map_data->map_copy[y][x] == EXIT)
		map_data->map_copy[y][x] = 'X';
	else 
	{	map_data->map_copy[y][x] = 'X';
		flood_fill(map_data, y + 1, x);
		flood_fill(map_data, y - 1, x);
		flood_fill(map_data, y, x + 1);
		flood_fill(map_data, y, x - 1);
	}
}

int	flood_check	(t_map *map_data)
{
	int	y;
	int	x;

	y = 0;
	while (map_data->map_copy[y])
	{
		x = 0;
		while (map_data->map_copy[y][x])
		{
			if(map_data->map_copy[y][x] == EXIT && map_data->map_copy[y][x] == COLLECT && map_data->map_copy[y][x] == 'X')
				return(0);
			// if (map_data->map_copy[y][x] != WALL && map_data->map_copy[y][x] != FLOOR && map_data->map_copy[y][x] != 'X')
			// 	return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	flood_path(t_map *map_data)
{
	player_pos(map_data);
	printf("W: %d\n H: %d\n", map_data->player_y /T_S, map_data->player_x /T_S);
	printf("3W: %d\n H: %d\n", map_data->width, map_data->hight);
	flood_fill(map_data, map_data->player_y / T_S, map_data->player_x / T_S);
	if (!flood_check(map_data))
	{
		free_map(map_data->map_copy);
		return(ft_printf("Map is not valid\n"), 0);
	}
	free_map(map_data->map_copy);
	return (1);
}