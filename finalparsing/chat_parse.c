#include "header.h"

int open_file(char *file)
{
	int openfile = open(file, O_RDONLY);
	if (openfile == -1)
	{
		write(1, "Failed to open the file", 24);
		return -1;
	}
	return (openfile);
}

ssize_t read_file(int openfile, char *buffer, size_t size)
{
	ssize_t bytesread = read(openfile, buffer, size);
	close(openfile);

	if (bytesread == -1)
	{
		write(1, "Failed to read from file", 25);
		return -1;
	}
	return (bytesread);
}

int parse_first_line(char *buffer, int *num, char *chars)
{
	int offset = 0;
	while (buffer[offset] != '.')
	{
		offset++;
	}

	*num = ft_atoi(ft_strndup(buffer, offset));

	for (int i = 0; i < 3; i++)
	{
		chars[i] = buffer[offset + i];
	}
	chars[3] = '\0';

	return (offset);
}

char **parse_lines(char *buffer, int num)
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

	for (int i = 0; i < 2; i++)
	{
		free(data[i]);
	}
	free(data);
}

// void parse_file(char *file)
// {
// 	int openfile = open_file(file);
// 	if (openfile == -1)
// 	{
// 		return ;
// 	}

// 	char buffer[MAX_SIZE];
// 	ssize_t bytesread = read_file(openfile, buffer, MAX_SIZE);
// 	if (bytesread == -1)
// 	{
// 		return ;
// 	}

// 	int num = 0;
// 	char chars[4];
// 	int offset = parse_first_line(buffer, &num, chars);

// 	char **data = parse_lines(buffer, num);
// 	if (data == NULL)
// 	{
// 		return ;
// 	}

// 	int num_rows = num;
// 	int num_cols = (ft_strlen(data[1]) / num) + 1;
// 	char **splitarray;

// 	int string_length = ft_strlen(data[1]) / 1;
// 	split_the_array(data[1], string_length, num_rows, num_cols, &splitarray);

// 	modify_array(splitarray, num_rows, num_cols, chars);

// 	if ((string_length + 1) % num_cols != 0)
// 	{
// 		write(1, "ERROR!!!!!\n", 12);
// 	}

// 	free_memory(data, num_rows, splitarray);
// }