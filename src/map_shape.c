/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_shape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:32:35 by msokolov          #+#    #+#             */
/*   Updated: 2025/03/11 15:44:12 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	map_shape(char **map)
{
	int i;
	int	first_row_lenght;

	i = 0;
	first_row_lenght = ft_strlen(map[0]);
	if (!map && map[0])
		return (0);
	while (map[i])
	{
		if (ft_strlen(map[i]) != first_row_lenght)
			return (ft_printf("Invalid Map Shape'\n"), 0);
		i++;
	}
	return (1);
}
