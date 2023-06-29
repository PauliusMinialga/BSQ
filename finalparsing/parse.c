/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 10:12:52 by pminialg      #+#    #+#                 */
/*   Updated: 2023/06/28 18:26:07 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	parse_file(char *file)
{
	int		openfile;
	char	buffer[MAX_SIZE];
	ssize_t	bytesread;
	int		num;
	char	chars[4];
	int		offset;
	int		length;
	int		i;
	char	**data;
	char	*line;
	int	line_index;

	openfile = open_file(file);
	if (openfile == -1)
	{
		return ;
	}
	bytesread = read_file(openfile, buffer, MAX_SIZE);
	if (bytesread == -1)
	{
		return ;
	}
	num = 0;
	offset = parse_first_line(buffer, &num, chars);
	data = parse_lines(buffer, num);
	if (data == NULL)
	{
		return ;
	}
	int num_rows = num;
	int num_cols = (ft_strlen(data[1]) / num) + 1;
	char **splitarray;
	int string_length = ft_strlen(data[1]) / 1;
	split_the_array(data[1], string_length, num_rows, num_cols, &splitarray);
	modify_array(splitarray, num_rows, num_cols, chars);
 // Print the split array
	// i = 0;
	// int j;
	// while (i < num_rows)
	// {
	// 	j = 0;
	// 	while (j < num_cols)
	// 	{
	// 		if (splitarray[i][j] == chars[0])
	// 		{
	// 			splitarray[i][j] = '1';
	// 		}
	// 		if (splitarray[i][j] == chars[1])
	// 		{
	// 			splitarray[i][j] = '0';
	// 		}
	// 		write(1, &splitarray[i][j], 1);
	// 		j++;
	// 	}
	// 	i++;
	// }
	if ((string_length + 1) % num_cols != 0)
	{
		write(1, "ERROR!!!!!\n", 12);
	}
	// i = 0;
	// while (i < num_rows)
	// {
	// 	free(splitarray[i]);
	// 	i++;
	// }
	// free(splitarray);
	free_memory(data, num_rows, splitarray);
}

void leaks(void)
{
	system("leaks a.out");
}

int	main(int argc, char *argv[])
{
	char	*file;

	atexit(leaks);
	file = "1.map";
	parse_file(file);
	return (0);
}
