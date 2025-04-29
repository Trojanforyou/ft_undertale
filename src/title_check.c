/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   title_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:29:07 by msokolov          #+#    #+#             */
/*   Updated: 2025/04/29 00:23:41 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int   title_check(t_map *map_data)
{
    int y;
    int x;
    
    y = 0;
    while (map_data->map[y])
    {
        x = 0;
        while (map_data->map[y][x])
        {
            if (map_data->map[y][x] == EXIT || map_data->map[y][x] == COLLECT ||
            map_data->map[y][x] == PLAYER || map_data->map[y][x] == FLOOR ||
            map_data->map[y][x] == WALL)
                x++;
            else
                return (ft_printf("Map has non valid titles\n"), 0);
        }
        y++;
    }
    return (1);
}