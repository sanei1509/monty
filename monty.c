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
	int line_number = 1, flag, a;
	stack_t *stack = NULL;
	void (*fn) (stack_t **, unsigned int);

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

	while ((getline(&line_read, &size, fp) != -1))
	{
		/*line_read = strtok(line_read, "\n\t");*/
		token = strtok(line_read, " \n\t");
		for (vari = 0, flag = 0, err_arg = 1, op_c = NULL; token != NULL; flag++)
		{
			if (flag == 0)
			{	
				op_c = token;
			}
			else if (flag == 1)
			{
				err_arg = 0;
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
		fn = inst_sel(op_c);
		if (fn == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op_c);
			exit(EXIT_FAILURE);
		}
		fn(&stack, line_number);
		line_number++;
	}

	free_dlistint(stack);
	free(line_read);  /*verficar que se este liberando*/
	fclose(fp);
	return (0);
}
