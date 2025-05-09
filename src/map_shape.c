/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_shape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:32:35 by msokolov          #+#    #+#             */
/*   Updated: 2025/05/09 18:16:54 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	map_shape(t_map *map_data)
{
	int	i;

	i = 0;
	if (!map_data->map)
		return (0);
	map_data->width = ft_strlen(map_data->map[0]);
	while (map_data->map[i])
	{
		if (ft_strlen(map_data->map[i]) != (size_t)map_data->width)
			{
				free_map(map_data->map);
				free_map(map_data->map_copy);
				ft_printf("Invalid Map Shape\n");
				return (0);
			}
		i++;
	}
	return (1);
}

int	valid_map(t_map *map_data)
{
	if (!pec_check(map_data))
		return (0);
	if (!wall_check(map_data))
		return (0);
	if (!title_check(map_data))
		return (0);
	if (map_shape(map_data))
		return (1);
	return (0);
}
