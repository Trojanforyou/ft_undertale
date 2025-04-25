/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:15:23 by msokolov          #+#    #+#             */
/*   Updated: 2025/04/25 15:07:29 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
void	player_hooks(void *param)
{
	t_map	*map_data;

	map_data = (void *)param;
    if (mlx_is_key_down(map_data->mlx, MLX_KEY_W))
        move_up(param);
    if (mlx_is_key_down(map_data->mlx, MLX_KEY_S))
        move_down(param);
    if (mlx_is_key_down(map_data->mlx, MLX_KEY_D))
        move_left(param);
    if (mlx_is_key_down(map_data->mlx, MLX_KEY_A))
        move_right(param);
}