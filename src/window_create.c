/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:09:17 by msokolov          #+#    #+#             */
/*   Updated: 2025/04/22 23:52:43 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	draw_map(t_map *map_data, t_images *images)
{
	int	y;
	int	x;
	
	y = 0;
	while (map_data->map[y])
	{
		x = 0;
		while (map_data->map[y][x])
		{
			if (map_data->map[y][x] == FLOOR)
				mlx_image_to_window(map_data->mlx, images->floor, x * T_S, y * T_S);
			else if (map_data->map[y][x] == WALL)
				mlx_image_to_window(map_data->mlx, images->wall, x * T_S, y * T_S);
			x++;
		}
		y++;
	}
}

void	draw_titles(t_map *map_data, t_images *images)
{
	int	y;
	int	x;

	y = 0;
	if (map_data->mlx == NULL || images->player == NULL || images->exit == NULL || images->collect == NULL)
	{
    	ft_printf("Error: One of the required images is NULL\n");
   		return;
	}
	while (map_data->map[y])
	
	{
		x = 0;
		while (map_data->map[y][x])
		{
			if (map_data->map[y][x] == COLLECT)
				mlx_image_to_window(map_data->mlx, images->collect, (x * T_S) 
				+ C_OFF, (y * T_S) + C_OFF);
			else if (map_data->map[y][x] == EXIT)
				mlx_image_to_window(map_data->mlx, images->exit, x * T_S, y * T_S);
			else if (map_data->map[y][x] == PLAYER)
			{
				ft_printf("Drawing at x=%d, y=%d, mlx=%p, image=%p\n", 
					x * T_S, y * T_S, (void*)map_data->mlx, (void*)images->player);
				mlx_image_to_window(map_data->mlx, images->player, x * T_S, y * T_S);
			}
			x++;
		}
		y++;
	}
	
}