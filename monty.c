#include "monty.h"
#include <string.h>
#include <sys/stat.h>

/**
 *main - take the argument from the command line 
 *@argc: number of arguments
 *@argv: array with the arguments passed
 */

int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	char *line_read = NULL, *token
	size_t size = 0;
	ssize_t read;

	if (argc != 2)
		return (EXIT_FAILURE);
	
	/*open the file with read permission*/
	fp = fopen(argv[1], "r");

	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line_read, &size, fp) != -1))
	{
		printf("leido: %s\n", line_read);
		/*tokenizing..*/

	}

	return (0);
}
