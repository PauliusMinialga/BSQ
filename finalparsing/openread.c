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