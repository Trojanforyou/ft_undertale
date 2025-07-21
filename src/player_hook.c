/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:15:23 by msokolov          #+#    #+#             */
/*   Updated: 2025/05/10 19:21:27 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	player_hooks(mlx_key_data_t keydata, void *param)
{
	t_map	*map_data;

	map_data = (t_map *)param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_up(map_data);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_down(map_data);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_right(map_data);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_left(map_data);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(map_data->mlx);
}
