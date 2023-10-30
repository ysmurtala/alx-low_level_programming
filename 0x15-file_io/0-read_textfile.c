#include "main.h"

/**
 * read_textfile -  function that reads a text file and prints it to stdout
 * @filename: filename
 * @letters: num of letters printed.
 *
 * Return: num of letters printed, if fails, returns 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int i;
	ssize_t d, r;
	char *buf;

	if (!filename)
		return (0);

	i = open(filename, O_RDONLY);

	if (i == -1)
		return (0);

	buf = malloc(sizeof(char) * (letters));
	if (!buf)
		return (0);

	d = read(i, buf, letters);
	r = write(STDOUT_FILENO, buf, d);

	close(i);

	free(buf);

	return (r);
}
