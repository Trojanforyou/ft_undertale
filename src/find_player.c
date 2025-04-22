/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:54:38 by msokolov          #+#    #+#             */
/*   Updated: 2025/04/04 15:54:38 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int    player_pos(t_map *map_data)
{
    int y;
    int x;
    y = 0;
    if (!map_data || !map_data->map)
        return (0);
    while (map_data->map[y])
    {
        x = 0;
        while (map_data->map[y][x])
        {
            if (map_data->map[y][x] == PLAYER)
            {
                map_data->player_y = y * T_S;
                map_data->player_x = x * T_S;
                return (1);
            }
            x++;
        }
        y++;
    }
    return (0);
}


