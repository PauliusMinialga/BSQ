/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfelida <mfelida@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:24:55 by mfelida           #+#    #+#             */
/*   Updated: 2023/06/28 14:25:23 by mfelida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int		x;
	t_point	coord;

	if (argc == 2)
		srand(atoi(argv[1]));
	else
		srand(42);
	int **map = calloc(DUMMY_Y_SIZE, sizeof(int *));
	int **check = calloc(DUMMY_Y_SIZE, sizeof(int *));
	for (int i = 0; i < DUMMY_Y_SIZE; i++)
	{
		map[i] = calloc(DUMMY_X_SIZE, sizeof(int));
		check[i] = calloc(DUMMY_X_SIZE, sizeof(int));
		if ((rand() % 10) * 2 < 6)
		{
			x = rand() % DUMMY_X_SIZE;
			map[i][x] = 1;
		}
		for (int j = 0; j < DUMMY_X_SIZE; j++)
		{
			check[i][j] = !(map[i][j]);
		}
	}
	// print_map(map);
	// printf("\n");
	coord = check_map(check);
	// print_map(check);
	// printf("\n");
	place_square(coord.x, coord.y, check[coord.y][coord.x], (int **) map);
	print_map(map);
	printf("\n");
	printf("%d:%d size %d", coord.x, coord.y, check[coord.y][coord.x]);
}
