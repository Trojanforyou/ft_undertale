/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:27:11 by msokolov          #+#    #+#             */
/*   Updated: 2025/04/25 15:14:33 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int init_game(t_map *map_data)
{
    t_images images;
    t_text text;
    texture_load(&text);
    image_load(map_data, &text, &images);
    player_textures(&text);
    draw_map(map_data, &images);
    player_images(map_data, &text, &images); 
    draw_titles(map_data, &images);
    // map_data->mlx = mlx_init(map_data->width, map_data->hight, "so_long", true);
    mlx_loop_hook(map_data->mlx, player_hooks, map_data);
    mlx_loop(map_data->mlx);
	mlx_terminate(map_data->mlx);
    return (1);
}


int main(int argc, char **argv)
{
    t_map map_data;

    if (argc != 2)
        return (0);
    map_data.mlx = mlx_init(800, 600, "So Long!", false);
    if (!map_data.mlx)
        return(ft_printf("Unable to create an window\n"), 0);
    if (!valid_file(argv[1]))
       return (0);
    map_data.map = map_reader(argv[1]);
    map_data.map_copy = map_reader(argv[1]);
    if (!map_data.map || !map_data.map_copy)
        return(ft_printf("Lox\n"), 0);
    if (!valid_map(&map_data) || !flood_path(&map_data))
       return (0);
    init_game(&map_data);
    return 0;
}



	
