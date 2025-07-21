/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 19:36:58 by msokolov          #+#    #+#             */
/*   Updated: 2025/05/10 19:38:17 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# define T_S 37 	// title_size
# define C_S 20 	// coin_size
# define E_S 37		// exit_size
# define C_OFF 8	// coin_offset

typedef enum e_map_elements
{
	WALL = '1',
	FLOOR = '0',
	COLLECT = 'C',
	PLAYER = 'P',
	EXIT = 'E',
}	t_map_elemets;

typedef struct s_text
{
	mlx_texture_t	*exit;
	mlx_texture_t	*floor;
	mlx_texture_t	*player;
	mlx_texture_t	*wall;
	mlx_texture_t	*collect;
	mlx_texture_t	*up;
	mlx_texture_t	*right;
	mlx_texture_t	*left;
}	t_text;

typedef struct s_image
{
	mlx_image_t		*exit;
	mlx_image_t		*floor;
	mlx_image_t		*wall;
	mlx_image_t		*player;
	mlx_image_t		*collect;
	mlx_image_t		*up;
	mlx_image_t		*right;
	mlx_image_t		*left;
}	t_images;

typedef struct s_map
{
	struct s_image		*images;
	struct s_text		*textures;
	char				**map;
	char				**map_copy;
	int					collect;
	int					exit;
	int					player;
	int					player_x;
	int					player_y;
	int					width;
	int					hight;
	int					counter;
	int					colle_count;
	mlx_t				*mlx;
}	t_map;

char	map_shape(t_map *map_data);
char	valid_file(char *name);
char	*map_str_reader(int fd);
char	**map_reader(char *script);
char	wall_check(t_map *map_data);

int		player_pos(t_map *map_data);
int		flood_check(t_map *map_data);
int		flood_path(t_map *map_data);
int		pec_last_check(t_map *map_data);
int		pec_check(t_map	*map_data);
int		find_last(char **map);
int		valid_map(t_map *map_data);
int		title_check(t_map *map_data);
int		title_and_wall(t_map *map_data);
int		coin_instance(t_map	*map_data, int x, int y);

void	flood_fill(t_map *map_data, int y, int x);
void	free_map(char **map);
void	texture_load(t_text *texture);
void	image_load(t_map *map_data, t_text *text, t_images *image);
void	draw_map(t_map *map_data, t_images *images);
void	player_textures(t_text *texture);
void	player_images(t_map *map_data, t_text *text, t_images *image);
void	draw_titles(t_map *map_data, t_images *images);
void	move_left(t_map *map_data);
void	move_right(t_map *map_data);
void	move_down(t_map *map_data);
void	move_up(t_map *map_data);
void	player_hooks(mlx_key_data_t keydata, void *param);
void	if_exit(t_map *map_data);
void	collected(t_map	*map_data);
#endif
