/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   split_the_array.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 12:36:52 by pminialg      #+#    #+#                 */
/*   Updated: 2023/06/28 17:20:30 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	split_the_array(const char *original_array, int length, int num_rows, int num_cols, char ***splitarray)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	index = 0;
	*splitarray = (char **)malloc(num_rows * sizeof(char *));
	while (i < num_rows)
	{
		(*splitarray)[i] = (char *)malloc(num_cols * sizeof(char));
		i++;
	}
	i = 0;
	while (i < num_rows)
	{
		j = 0;
		while (j < num_cols)
		{
			if (index < length)
			{
				(*splitarray)[i][j] = original_array[index++];
			}
			else
			{
				(*splitarray)[i][j] = '\0';
			}
			j++;
		}
		i++;
	}
}
