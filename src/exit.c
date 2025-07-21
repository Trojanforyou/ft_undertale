/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:13:41 by msokolov          #+#    #+#             */
/*   Updated: 2025/05/10 19:32:41 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	if_exit(t_map *map_data)
{
	int	y;
	int	x;

	y = map_data->player_y / T_S;
	x = map_data->player_x / T_S;
	if (map_data->map[y][x] == EXIT &&
		map_data->colle_count == map_data->collect)
	{
		printf("\t \tYou WON\n");
		mlx_close_window(map_data->mlx);
	}
}
