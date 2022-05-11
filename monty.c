#include "monty.h"

/**
 *main - take the argument from the command line
 *@argc: number of arguments
 *@argv: array with the arguments passed
 *Return: 0
 */

int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	char *line_read = NULL, *token = NULL, *op_c = NULL;
	size_t size = 0;
	ssize_t read = 0;
	int line_number = 1;
	int flag;
	extern char *vari;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line_read, &size, fp) != -1))
	{
		op_c = NULL;
		vari = NULL;
		flag = 0;
		line_read = strtok(line_read, "\n\t");
		token = strtok(line_read, " ");
		while (token != NULL)
		{
			if (flag == 0)
			{	
				flag = 1;
				op_c = token;
			}
			else
				vari = token;

			token = strtok(NULL, " ");
		}
		inst_sel(op_c, line_number);
		line_number++;
	}
	free(line_read);
	/*verficar que se este liberando*/
	fclose(fp);
	exit(EXIT_SUCCESS);
	return (0);
}
