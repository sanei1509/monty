#include "monty.h"

/**
 *main - take the argument from the command line
 *@argc: number of arguments
 *@argv: array with the arguments passed
 *Return: 0
 */

int main(int argc, char *argv[])
{
	char *line_read = NULL, *token2 = NULL, *op_c = NULL;
	size_t size = 0;
	int line_number = 1;
	stack_t *stack = NULL;
	void (*fn)(stack_t**, unsigned int);	
	gl.fp = NULL;	
	gl.line_read = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	gl.fp = fopen(argv[1], "r");
	if (gl.fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((getline(&gl.line_read, &size, gl.fp) != -1))
	{
		gl.vari = 0;
		gl.err_arg = 1;
		op_c = NULL;

		op_c = strtok(gl.line_read, " \n\t");
		token2 = strtok(NULL, " \n\t");
		if (token2)
			gl.vari = atoi(token2);

		if (check_token(token2) == 0)
			gl.err_arg = 0;
		else
			gl.err_arg = 1;

		fn = inst_sel(op_c);

		if (fn == NULL)
		{
			free_dlistint(stack);
			free(gl.line_read);
			fclose(gl.fp);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op_c);
			exit(EXIT_FAILURE);
		}
		/* check status: FN != NULL */
		fn(&stack, line_number);
		line_number++;
	}

	free_dlistint(stack);
	free(gl.line_read);  /*verficar que se este liberando*/
	fclose(gl.fp);
	return (0);
}
