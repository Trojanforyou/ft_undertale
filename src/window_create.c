/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:09:17 by msokolov          #+#    #+#             */
/*   Updated: 2025/05/10 19:36:07 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	draw_map(t_map *map_data, t_images *images)
{
	int	y;
	int	x;

	y = -1;
	if (!images->collect || !images->exit || !images->floor || !images->player
		|| !images->wall)
	{
		ft_printf("An Error accured while drawing map\n");
		exit(1);
	}
	while (map_data->map[++y])
	{
		x = -1;
		while (map_data->map[y][++x])
		{
			if (map_data->map[y][x] == FLOOR
				|| map_data->map[y][x] == PLAYER || map_data->map[y][x] == EXIT
				|| map_data->map[y][x] == COLLECT)
				mlx_image_to_window(map_data->mlx,
					images->floor, x * T_S, y * T_S);
			else if (map_data->map[y][x] == WALL)
				mlx_image_to_window(map_data->mlx,
					images->wall, x * T_S, y * T_S);
		}
	}
}

void	draw_titles(t_map *map_data, t_images *images)
{
	int	y;
	int	x;

	y = -1;
	if (map_data->mlx == NULL || images->player == NULL
		|| images->exit == NULL || images->collect == NULL)
		exit(1);
	while (map_data->map[++y])
	{
		x = -1;
		while (map_data->map[y][++x])
		{
			if (map_data->map[y][x] == COLLECT)
				mlx_image_to_window(map_data->mlx,
					images->collect, (x * T_S) + C_OFF, (y * T_S) + C_OFF);
			else if (map_data->map[y][x] == EXIT)
				mlx_image_to_window(map_data->mlx,
					images->exit, x * T_S, y * T_S);
			else if (map_data->map[y][x] == PLAYER)
				mlx_image_to_window(map_data->mlx, images->player, x
					* T_S, y * T_S);
		}
	}
}
