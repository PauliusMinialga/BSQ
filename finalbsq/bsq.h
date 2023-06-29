/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfelida <mfelida@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:49:14 by mfelida           #+#    #+#             */
/*   Updated: 2023/06/28 14:31:09 by mfelida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# define DUMMY_X_SIZE 175
# define DUMMY_Y_SIZE 80

typedef struct point
{
	int	x;
	int	y;
}	t_point;
//	map_funcs.c
void	place_square(int x, int y, int size, int **map);
void	print_map(int **map);
//	map_solver.c
t_point	check_map(int **map);
#endif