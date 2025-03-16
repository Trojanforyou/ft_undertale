#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft.h"
#include "MLX42/MLX42.h"
# define T_S 37
# define C_S 20
# define E_S 37
# define C_OFF 8
typedef enum e_map_elements
{
	WALL = '1',
	FLOOR = '0',
	COLLECT = 'C',
	PLAYER = 'P',
	EXIT = 'E',
}	t_map_elemets;

typedef struct s_map
{
	char	**map;
	char	**map_copy;
	int		collect;
	int		exit;
	int		player;
	int		player_x;
	int		player_y;
	int		width;
	int		height;
}	t_map;


#endif
