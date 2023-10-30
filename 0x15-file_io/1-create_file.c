#include "main.h"

/**
 * create_file - function that creates a file
 * @filename: filename
 * @text_content: content to write in the file
 *
 * Return: 1 at success, -1 at failure
 */
int create_file(const char *filename, char *text_content)
{
	int a;
	int nletters;
	int b;

	if (!filename)
		return (-1);

	a = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (a == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (nletters = 0; text_content[nletters]; nletters++)
		;

	b = write(a, text_content, nletters);

	if (b == -1)
		return (-1);

	close(a);

	return (1);
}
