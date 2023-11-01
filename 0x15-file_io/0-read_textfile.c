#include "main.h"

/**
 * read_textfile -  file
 * @filename: file used
 * @letters: letter
 *
 * Return: int retd
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd, readers, writer;
	char *buffe;

	if (!filename)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	buffe = malloc(sizeof(char) * letters);
	if (!buffe)
		return (0);
	readers = read(fd, buffe, letters);
	if (readers < 0)
	{
		free(buffe);
		return (0);
	}
	buffe[readers] = '\0';
	close(fd);
	writer = write(STDOUT_FILENO, buffe, readers);
	if (writer < 0)
	{
		free(buffe);
		return (0);
	}
	free(buffe);
	return (writer);
}
