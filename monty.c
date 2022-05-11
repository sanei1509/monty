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
	extern int vari;
	extern int err_arg;
	int a;

	err_arg = 0;

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
		err_arg = 0;
		op_c = NULL;
		vari = 0; /*before NULL*/
		flag = 0;
		line_read = strtok(line_read, "\n\t");
		token = strtok(line_read, " ");
		while (token != NULL)
		{
			printf("%s\n", token);
			if (flag == 0)
			{	
				flag = 1;
				op_c = token;
			}
			else if (flag == 1)
			{
				vari = atoi(token);
				if (vari == 0)
				{
					for (a = 0; token[a] != '\0'; a++)
					{
						if (token[a] != '0')
						{
							err_arg = 1;
							break;
						}
					}
				}
				flag = 2;
			}
			token = strtok(NULL, " ");
		}
		inst_sel(op_c);
		line_number++;
	}
	vari = 5;
	inst_sel("push");
	free(line_read);
	/*verficar que se este liberando*/
	fclose(fp);
	exit(EXIT_SUCCESS);
	return (0);
}
