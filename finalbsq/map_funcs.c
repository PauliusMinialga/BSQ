/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfelida <mfelida@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:08:43 by mfelida           #+#    #+#             */
/*   Updated: 2023/06/28 16:15:36 by mfelida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

void	place_square(int x, int y, int size, int **map)
{
	int	ix;
	int	iy;

	y = y - size + 1;
	x = x - size + 1;
	iy = y;
	while (iy < y + size)
	{
		ix = x;
		while (ix < x + size)
		{
			map[iy][ix] = 2;
			ix++;
		}
		iy++;
	}
}

void	print_map(int **map)
{
	int	y;
	int	x;

	y = 0;
	while (y < DUMMY_Y_SIZE)
	{
		x = 0;
		while (x < DUMMY_X_SIZE)
		{
			printf("%d ", map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}
