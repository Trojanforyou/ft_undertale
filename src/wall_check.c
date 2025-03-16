/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:44:59 by msokolov          #+#    #+#             */
/*   Updated: 2025/03/12 15:15:38 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	wall_check(char **map)
{
	int	i;
	int	j;
	int	last_row;
	int	last_col;

	i = 0;
	j = 0;
	last_row = find_last(map);
	last_col = ft_strlen(map[0]) - 1;
	while (i <= last_row)
	{
		if (map[i][0] != '1' || map[i][last_col] != '1')
			return(ft_printf("Invalid Map Structure\n"), 0);
		i++;
	}
	while (j <= last_col)
	{
		if (map[0][j] != '1' || map[last_row][j] != '1')
			return(ft_printf("Invalid Map Structure\n"), 0);
		j++;
	}
	return (1);
}
