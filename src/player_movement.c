/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:45:28 by msokolov          #+#    #+#             */
/*   Updated: 2025/04/25 16:29:24 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void    move_left(t_map *map_data)
{
	if (map_data->map[map_data->player_y][map_data->player_x - 1] == WALL)
		return;
    map_data->player_x -= 1;    
	map_data->image->left->instances[0].x = map_data->player_x * T_S;
	map_data->image->left->instances[0].y = map_data->player_y * T_S;
	map_data->image->left->enabled = true;
	map_data->image->right->enabled = false;
	map_data->image->up->enabled = false;
	map_data->image->player->enabled = false;
}

void    move_right(t_map *map_data)
{
	if (map_data->map[map_data->player_y][map_data->player_x + 1] == WALL)
		return;
    map_data->player_x += 1;    
    map_data->image->right->instances[0].x = map_data->player_x * T_S;
	map_data->image->right->instances[0].y = map_data->player_y * T_S;
	map_data->image->left->enabled = false;
	map_data->image->right->enabled = true;
    map_data->image->up->enabled = false;
	map_data->image->player->enabled = false;
}

void    move_down(t_map *map_data)
{
	if (map_data->map[map_data->player_y + 1 * T_S][map_data->player_x * T_S] == WALL)
		return;
    map_data->player_y += 1;    
	map_data->image->player->instances[0].x = map_data->player_x * T_S;
	map_data->image->player->instances[0].y = map_data->player_y * T_S;
	map_data->image->left->enabled = false;
	map_data->image->right->enabled = false;
	map_data->image->up->enabled = false;
	map_data->image->player->enabled = true;
}
void    move_up(t_map *map_data)
{
    printf("player_y: %d, player_x: %d\n", map_data->player_y, map_data->player_x);
    printf("map address: %p\n", (void*)map_data->map);
    if (map_data->player_y == 0 ||
        map_data->map[map_data->player_y - 1 / T_S][map_data->player_x / T_S] == WALL)
        return;  
    map_data->player_y -= 1;    
	map_data->image->up->instances[0].x = map_data->player_x;
	map_data->image->up->instances[0].y = map_data->player_y;
	map_data->image->left->enabled = false;
	map_data->image->right->enabled = false;
	map_data->image->up->enabled = true;
	map_data->image->player->enabled = false;
}