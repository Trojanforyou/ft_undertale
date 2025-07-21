/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:27:11 by msokolov          #+#    #+#             */
/*   Updated: 2025/05/12 16:42:47 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	init_game(t_map *map_data)
{
	t_images	images;
	t_text		text;

	map_data->counter = 0;
	map_data->hight = find_last(map_data->map);
	map_data->width = ft_strlen(map_data->map[0]);
	map_data->mlx = mlx_init(map_data->width * T_S,
			map_data->hight * T_S, "so_long", false);
	if (!map_data->mlx)
		return (free(map_data->mlx), 0);
	texture_load(&text);
	image_load(map_data, &text, &images);
	player_textures(&text);
	draw_map(map_data, &images);
	player_images(map_data, &text, &images);
	draw_titles(map_data, &images);
	mlx_key_hook(map_data->mlx, player_hooks, map_data);
	mlx_loop(map_data->mlx);
	mlx_terminate(map_data->mlx);
	return (1);
}

int	main(int argc, char **argv)
{
	t_map	map_data;

	if (argc != 2)
		return (0);
	if (!valid_file(argv[1]))
		return (0);
	map_data.map = map_reader(argv[1]);
	map_data.map_copy = map_reader(argv[1]);
	if (!map_data.map || !map_data.map_copy)
	{
		free_map(map_data.map);
		free_map(map_data.map_copy);
		return (ft_printf("Map is not exist\n"), 0);
	}
	if (!valid_map(&map_data) || !flood_path(&map_data))
	{
		free_map(map_data.map);
		free_map(map_data.map_copy);
		return (0);
	}
	init_game(&map_data);
	free_map(map_data.map);
	return (0);
}
