#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char *ft_strndup(char *str, size_t n) {
    size_t length = ft_strlen(str);
    if (n < length) {
        length = n;
    }

    char *dup = (char *)malloc((length + 1) * sizeof(char));
    if (dup == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < length; i++) {
        dup[i] = str[i];
    }
    dup[length] = '\0';
    return (dup);
}

int	ft_atoi(char *str)
{
	unsigned int	nb;
	int				sign;
	int				i;

	i = 0;
	sign = 0;
	nb = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += str[i++] - '0';
	}
	if (sign % 2 == 1)
		return (nb * -1);
	return (nb);
}


char *ft_strtok(char *str, char *delim) {
    char *nextToken = NULL;
    char *endOfStr = NULL;

    if (str != NULL) {
        nextToken = str;
        endOfStr = str + ft_strlen(str);
    } else if (nextToken == NULL || *nextToken == '\0') {
        return NULL;
    }

    char *token = nextToken;
    while (nextToken < endOfStr) {
        int isDelimiter = 0;
        size_t i = 0;
        while (delim[i] != '\0') {
            if (*nextToken == delim[i]) {
                isDelimiter = 1;
                break;
            }
            i++;
        }

        if (isDelimiter) {
            *nextToken = '\0';
            nextToken++;
            return token;
        }
        nextToken++;
    }

    nextToken = NULL;
    return (token);
}

void	parse_file(char *file)
{
	int	openfile;
	/*opening, reading and closing the file*/
	openfile = open(file, O_RDONLY);
	if (openfile == -1)
	{
		write(1, "Failed to open the file", 24);
		return ;
	}
	
	char	buffer[MAX_SIZE];
	ssize_t bytesread;

	bytesread = read(openfile, buffer, MAX_SIZE);
	if (bytesread == -1)
	{
		write(1, "Failed to read from file", 25);
		return ;
	}
	close(openfile);

	/*parsing the first line*/
	int		num;
	char	chars[4];
	int		offset;
	int		length;

	offset = 0;
	length = 0;
	while (buffer[offset] != '.')
	{
		length++;
		offset++;
	}
	num = ft_atoi(ft_strndup(buffer, length));
	// offset++;
	printf("%d \n", num); // remove later
	int i;

	i = 0;
	while (i < 3)
	{
		chars[i] = buffer[offset + i];
		i++;
	}
	chars[3] = '\0';
	printf("%s - the whole string\n", chars); // running some checks
	/*i have num with the number and chars string with the characters*/

	/*now i'm parsing the rest of the file*/
	char **data = (char**)malloc(num * sizeof(char*));
    if (data == NULL) {
        write(1, "Failed to allocate memory", 26);
        return;
    }
	int line_index;
	char *line= ft_strtok(buffer, "\n");

	offset = 0;
	line_index = 0;
	// line = ft_strtok(buffer, "\n"); // splitting buffer into lines

	while (line != NULL)
	{
        int lineLength = ft_strlen(line);
		// printf("line is - %d\n", lineLength);
        data[line_index] = (char*)malloc((lineLength + 1) * sizeof(char));
        if (data[line_index] == NULL)
		{
            write(1, "Failed to allocate memory", 26);
            // Free previously allocated memory
            for (int i = 0; i < line_index; i++) // for loop here
			{
                free(data[i]);
            }
            free(data);
            return;
        }
	 	ft_strcpy(data[line_index], line);
        // Replace the printf statement
        printf("Line %d: %s\n", line_index+1, data[line_index]);
		printf("line index - %d\n", line_index);
        line_index++;
        line = ft_strtok(NULL, "\n");
	}
	i = 0;
	while(i < num)
	{
		free(data[i]);
		i++;
	}
	free(data[i]);
}

int	main(int argc, char *argv[])
{
	char	*file;

	file = "example_file";
	parse_file(file);
	return (0);
}