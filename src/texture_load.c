/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:01:19 by msokolov          #+#    #+#             */
/*   Updated: 2025/04/05 16:01:19 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void    texture_load(t_text *texture)
{
	texture->wall = mlx_load_png("./textures/wall2.png");
	texture->floor = mlx_load_png("./textures/floor2.png");
	texture->exit = mlx_load_png("./textures/exit2.png");
	texture->collect = mlx_load_png("./textures/collect.png");
	if (!texture->floor || !texture->wall || !texture->collect 
		|| !texture->exit)
		{
			ft_printf("An Error occured while loading textures\n");
			return ;
		}
	}

void    image_load(t_map *map_data, t_text *texture, t_images *image)
{	
	map_data->images = image;
	map_data->textures = texture;
	image->exit = mlx_texture_to_image(map_data->mlx, texture->exit);
	image->floor = mlx_texture_to_image(map_data->mlx, texture->floor);
	image->collect = mlx_texture_to_image(map_data->mlx, texture->collect);
	image->wall = mlx_texture_to_image(map_data->mlx, texture->wall);
	if (!image->wall || !image->collect || !image->exit
		|| !image->floor)
		{
			ft_printf("An Error occured while loading images\n");
			return ;
		}
		mlx_delete_texture(texture->exit);
		mlx_delete_texture(texture->floor);
		mlx_delete_texture(texture->collect);
		mlx_delete_texture(texture->wall);
}
	
void    player_textures(t_text	*texture)
{
	texture->player = mlx_load_png("./textures/frisk.png");
	texture->up = mlx_load_png("./textures/up.png");
	texture->left = mlx_load_png("./textures/left.png");
	texture->right = mlx_load_png(("./textures/right.png"));
	if (!texture->up || !texture->left || !texture->right || !texture->player)
	{
		ft_printf("An error occured while loading player txt\n");
		return ;
	}
}

void	player_images(t_map *map_data, t_text *text, t_images *image)
{
	image->player = mlx_texture_to_image(map_data->mlx, text->player);
	image->up = mlx_texture_to_image(map_data->mlx, text->up);
	image->right = mlx_texture_to_image(map_data->mlx, text->right);
	image->left = mlx_texture_to_image(map_data->mlx, text->left);
	if (!image->player || !image->up || !image->right || !image->left)
	{
		ft_printf("An Error occured while loading player img\n");
		return ;
	}
	mlx_delete_texture(text->player);
	mlx_delete_texture(text->up);
	mlx_delete_texture(text->right);
	mlx_delete_texture(text->left);
}