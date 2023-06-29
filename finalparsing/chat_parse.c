/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   chat_parse.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 18:14:44 by pminialg      #+#    #+#                 */
/*   Updated: 2023/06/28 18:17:20 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	parse_first_line(char *buffer, int *num, char *chars)
{
	int	offset;
	int	i;

	offset = 0;
	i = 0;
	while (buffer[offset] != '.')
	{
		offset++;
	}
	*num = ft_atoi(ft_strndup(buffer, offset));
	while (i < 3)
	{
		chars[i] = buffer[offset + i];
		i++;
	}
	chars[3] = '\0';
	return (offset);
}

char	**parse_lines(char *buffer, int num)
{
	char **data = (char **)malloc(num * sizeof(char *));
	if (data == NULL)
	{
		write(1, "Failed to allocate memory", 26);
		return NULL;
	}

	char *line;
	int line_index = 0;
	line = ft_strtok(buffer, "\n");

	while (line != NULL)
	{
		int lineLength = ft_strlen(line);
		data[line_index] = (char *)malloc((lineLength + 1) * sizeof(char));
		if (data[line_index] == NULL)
		{
			write(1, "Failed to allocate memory", 26);
			// Free previously allocated memory
			for (int i = 0; i < line_index; i++)
			{
				free(data[i]);
			}
			free(data);
			return NULL;
		}
		ft_strcpy(data[line_index], line);
		line_index++;
		line = ft_strtok(NULL, "\n");
	}

	return (data);
}

void modify_array(char **splitarray, int num_rows, int num_cols, char *chars)
{
	for (int i = 0; i < num_rows; i++)
	{
		for (int j = 0; j < num_cols; j++)
		{
			if (splitarray[i][j] == chars[0])
			{
				splitarray[i][j] = '1';
			}
			else if (splitarray[i][j] == chars[1])
			{
				splitarray[i][j] = '0';
			}
			write(1, &splitarray[i][j], 1);
		}
	}
}

void free_memory(char **data, int num_rows, char **splitarray)
{
	for (int i = 0; i < num_rows; i++)
	{
		free(splitarray[i]);
	}
	free(splitarray);

	for (int i = 0; i < num_rows; i++)
	{
		free(data[i]);
	}
	free(data);
}
