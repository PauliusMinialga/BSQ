/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfelida <mfelida@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:52:46 by mfelida           #+#    #+#             */
/*   Updated: 2023/06/28 16:33:49 by mfelida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>

#define READ_BUFFER_SIZE 10000

int	read_line(int fptr, char *buffer)
{
	int		res;
	char	c;

	c = '\0';
	res = read(fptr, &c, 1);
	while (c != '\n' && res > 0)
	{
		*buffer = c;
		res = read(fptr, &c, 1);
		buffer++;
	}
	*buffer = '\0';
	return (res);
}

char	*ft_find_symbols(char *str)
{
	char	*res;
	int		i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (ft_strlen(str + i) != 3)
		return (-1);
	
	return (str + i);
}

int	get_buffer_size(char *filepath)
{
	int		f;
	int		i;
	char	read_buffer[2][READ_BUFFER_SIZE];
	char	*valid_symbols;

	f = open(filepath, O_RDONLY);
	i = 0;
	while (read_line(f, read_buffer[i]) > 0 && i < 2)
		i++;
	close(f);
	if (i < 2)
		return (-1);
	valid_symbols = ft_find_symbols(read_buffer[0]);
	if (ft_strlen(valid_symbols) != 3)
		return (-1);
	i = 0;
	while (read_buffer[1][i])
	{
		if (!ft_char_in_str(read_buffer[1][i], valid_symbols))
			return (-1);
		i++;
	}
	return (i);
}
