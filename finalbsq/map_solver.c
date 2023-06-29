/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_solver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfelida <mfelida@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:48:08 by mfelida           #+#    #+#             */
/*   Updated: 2023/06/27 15:53:38 by mfelida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	minimum(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	check_cell(int x, int y, int **map)
{
	int	min;

	if (map[y][x])
	{
		min = map[y - 1][x - 1];
		min = minimum(min, map[y][x - 1]);
		min = minimum(min, map[y - 1][x]);
		map[y][x] = min + 1;
	}
	return (map[y][x]);
}

t_point	check_map(int **map)
{
	int		curr_cell;
	int		max;
	int		x;
	int		y;
	t_point	coord;

	max = 0;
	y = 1;
	while (y < DUMMY_Y_SIZE)
	{
		x = 1;
		while (x < DUMMY_X_SIZE)
		{
			curr_cell = check_cell(x, y, map);
			if (curr_cell > max)
			{
				coord.x = x;
				coord.y = y;
				max = curr_cell;
			}
			x++;
		}
		y++;
	}
	return (coord);
}
