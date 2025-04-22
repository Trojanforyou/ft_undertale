/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pec_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:29:55 by msokolov          #+#    #+#             */
/*   Updated: 2025/04/07 17:48:04 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	pec_check(t_map	*map_data)
{
	int i;
	int j;

	i = 0;
	map_data->collect = 0;
	map_data->exit = 0;
	map_data->player = 0;
	while(map_data->map[i])
	{
		j = 0;
		while (map_data->map[i][j])
		{
			if (map_data->map[i][j] == PLAYER)
				map_data->player++;
			if (map_data->map[i][j] == COLLECT)
				map_data->collect++;
			if (map_data->map[i][j] == EXIT)
				map_data->exit++;
			j++;
		}
		i++;
	}
	pec_last_check(map_data);
	return (1);
}
int	pec_last_check(t_map *map_data)
{
	if (map_data->collect < 1)
		return(ft_printf("Invalid Collectable Number\n"), 0);
	if (map_data->player != 1)
		return (ft_printf("Invalid Player Number\n"), 0);
	if (map_data->exit != 1)
		return (ft_printf("Invalid Exit Number\n"), 0);
	return (1);
}

