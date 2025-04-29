/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:45:28 by msokolov          #+#    #+#             */
/*   Updated: 2025/04/29 16:35:38 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void    move_up(t_map *map_data)
{
    if (map_data->player_y == 0 ||
        map_data->player_x == 0 || map_data->map[(map_data->player_y - T_S) / T_S][(map_data->player_x) / T_S] == WALL)
        return;
    mlx_image_to_window(map_data->mlx, map_data->images->up, (map_data->player_x * 50), (map_data->player_y * 50));
    map_data->player_y -= T_S;
    collected(map_data);
    if_exit(map_data);
    map_data->images->up->instances[0].x = map_data->player_x;
    map_data->images->up->instances[0].y = map_data->player_y;
    map_data->images->left->enabled = false;
    map_data->images->right->enabled = false;
    map_data->images->up->enabled = true;
    map_data->images->player->enabled = false;
}
void    move_left(t_map *map_data)
{
	if (map_data->player_y == 0 ||
        map_data->player_x == 0 || map_data->map[(map_data->player_y) / T_S][(map_data->player_x - T_S) / T_S] == WALL)
		return;
    mlx_image_to_window(map_data->mlx, map_data->images->left, (map_data->player_x * 50), (map_data->player_y * 50));
    map_data->player_x -= T_S;    
    if (map_data->map[map_data->player_y / T_S][map_data->player_x / T_S] == COLLECT)
        collected(map_data);
    if_exit(map_data);
	map_data->images->left->instances[0].x = map_data->player_x;
	map_data->images->left->instances[0].y = map_data->player_y;
	map_data->images->left->enabled = true;
	map_data->images->right->enabled = false;
	map_data->images->up->enabled = false;
	map_data->images->player->enabled = false;
}

void    move_right(t_map *map_data)
{
	if (map_data->player_y == 0 ||
        map_data->player_x == 0 || map_data->map[(map_data->player_y) / T_S][(map_data->player_x + T_S) / T_S] == WALL)
		return;
    mlx_image_to_window(map_data->mlx, map_data->images->right, (map_data->player_x * 50), (map_data->player_y * 50));
    map_data->player_x += T_S;    
    if (map_data->map[map_data->player_y / T_S][map_data->player_x / T_S] == COLLECT)
        collected(map_data);
    if_exit(map_data);    
    map_data->images->right->instances[0].x = map_data->player_x;
	map_data->images->right->instances[0].y = map_data->player_y;
	map_data->images->left->enabled = false;
	map_data->images->right->enabled = true;
    map_data->images->up->enabled = false;
	map_data->images->player->enabled = false;
}

void    move_down(t_map *map_data)
{
	if (map_data->player_y == 0 ||
        map_data->player_x == 0 || map_data->map[(map_data->player_y + T_S) / T_S][(map_data->player_x) / T_S] == WALL)
		return;
    map_data->player_y += T_S;
    if  (map_data->map[map_data->player_y / T_S][map_data->player_x / T_S] == COLLECT)
        collected(map_data);
    if_exit(map_data);
	map_data->images->player->instances[0].x = map_data->player_x;
	map_data->images->player->instances[0].y = map_data->player_y;
	map_data->images->left->enabled = false;
	map_data->images->right->enabled = false;
	map_data->images->up->enabled = false;
	map_data->images->player->enabled = true;
}