#include "monty.h"

/**
 *print_error - handle error of args/open the file and handle error
 *@argc: receive number of arguments
 *@name_file: receive the op_code to execute
 */
void print_error(int argc, char *name_file)
{
	gl.fp = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
	}
	/*open and save return NULL or pointer to the file*/
	gl.fp = fopen(name_file, "r");
	if (gl.fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", name_file);
		exit(EXIT_FAILURE);
	}
}

/**
 *main - take the argument from the command line
 *@argc: number of arguments
 *@argv: array with the arguments passed
 *Return: 0
 */

int main(int argc, char *argv[])
{
	char *token2 = NULL, *op_c = NULL;
	size_t size = 0;
	int line_number = 1;
	stack_t *stack = NULL;
	void (*fn)(stack_t**, unsigned int);

	gl.line_read = NULL;
	print_error(argc, argv[1]);

	while ((getline(&gl.line_read, &size, gl.fp) != -1))
	{
		gl.err_arg = -1;
		op_c = NULL;

		op_c = strtok(gl.line_read, " \n\t");
		if (op_c == NULL || op_c[0] == '#')
			continue;
		token2 = strtok(NULL, " \n\t");
		if (token2)
			gl.vari = atoi(token2);

		if (check_token(token2) == 0)
			gl.err_arg = 0;
		else
			gl.err_arg = -1;

		fn = inst_sel(op_c);

		if (fn == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op_c);
			free_dlistint(stack);
			free(gl.line_read);
			fclose(gl.fp);
			exit(EXIT_FAILURE);
		}
		fn(&stack, line_number);
		line_number++;
	}
	free_dlistint(stack);
	free(gl.line_read);
	fclose(gl.fp);
	return (0);
}
