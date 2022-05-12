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
	char *line_read = NULL, *token2 = NULL, *op_c = NULL;
	size_t size = 0;
	int line_number = 1;
	stack_t *stack = NULL;
	void (*fn)(stack_t**, unsigned int);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((getline(&line_read, &size, fp) != -1))
	{
		vari = 0;
		err_arg = 1;
		op_c = NULL;

		op_c = strtok(line_read, " \n\t");
		token2 = strtok(NULL, " \n\t");
		if (token2)
			vari = atoi(token2);

		if (check_token(token2) == 0)
			err_arg = 0;
		else
			err_arg = 1;

		fn = inst_sel(op_c);

		if (fn == NULL)
		{
			free_dlistint(stack);
			free(line_read);
			fclose(fp);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op_c);
			exit(EXIT_FAILURE);
		}
		/* check status: FN != NULL */
		fn(&stack, line_number);
		line_number++;
	}

	free_dlistint(stack);
	free(line_read);  /*verficar que se este liberando*/
	fclose(fp);
	return (0);
}
