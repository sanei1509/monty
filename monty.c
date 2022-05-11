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
	char *line_read = NULL, *token = NULL;
	size_t size = 0;
	ssize_t read = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit (EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line_read, &size, fp) != -1))
	{
		line_read = strtok(line_read, "\n\t$");
		token = strtok(line_read, " ");
		while (token != NULL)
		{
			printf("tokenized line-%s\n", token); 
			token = strtok(NULL, " ");
		}
	}

	
	free(line_read);
	fclose(fp);
	exit(EXIT_SUCCESS);
	return (0);
}