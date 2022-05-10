#include "monty.h"
#include <string.h>
#include <sys/stat.h>

/**
 *parser_line - function to parse the array
 *@array: the array charged with path
 *@line: line line
 *Return: return the array charged
 */
/**
char **parser_line(char **array, char *line)
{
	int i = 0;
	char *token = NULL;

	line = strtok(line, "\n");
	line = strtok(line, "\t");
	array = malloc(sizeof(char *) * 2);
	token = strtok(line, " ");

	while (token != NULL)
	{
		array[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	return (array);
}
*/



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
	ssize_t read;
	int i = 0;

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
		line_read = strtok(line_read, "\n");
		token = strtok(line_read, " ");
		while (token != NULL)
		{
			printf("tokenized line-%s\n", token); 
			token = strtok(NULL, " ");
			i++;
		}
		printf("linea leida:%s\n", line_read);
	}
	printf("ultima linea: %s\n", line_read);

	return (0);
}
