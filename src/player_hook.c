/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:15:23 by msokolov          #+#    #+#             */
/*   Updated: 2025/04/09 19:57:41 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	player_w_s(t_map *map_data)
{
    if (mlx_is_key_down(map_data->mlx, MLX_KEY_W))
    {
        if (map_data->map[map_data->player_y - 1][map_data->player_x] != '1')
        
    }
}