/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collected.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 00:10:52 by msokolov          #+#    #+#             */
/*   Updated: 2025/04/29 15:17:40 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	coin_instance(t_map *map_data, int x, int y)
{
	size_t i = 0;
	
	while (i < map_data->images->collect->count)
	{
		if (map_data->images->collect->instances[i].x / T_S == x && 
		    map_data->images->collect->instances[i].y / T_S == y)
			return (i);
		i++;
	}
	return (-1);
}

void collected(t_map *map_data)
{
	int i;
	int x;
	int y;

	x = map_data->player_x / T_S;
	y = map_data->player_y / T_S;
	
	if (map_data->map[y][x] == COLLECT)
	{
		map_data->map[y][x] = '0';
		map_data->colle_count++;
		i = coin_instance(map_data, x, y);
		if (i != -1)
		{
			map_data->images->collect->instances[i].x = -100;
			map_data->images->collect->instances[i].y = -100;
		}
	}
}
