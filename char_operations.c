#include "monty.h"


/**
* pchar - print top value of the stack as char
* @head: pointer to first node of the list
* @line_number: line number of the file with byte code
*/
void pchar(stack_t **head, unsigned int line_number __attribute__((unused)))
{
	stack_t *c_node = *head;

	/*if (c_node->n <= 127)
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
	
	else if */
	if (*head != NULL)
	{
		printf("%c\n", c_node->n);
		return;
	}
	else
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);

	fclose(gl.fp);
	free(gl.line_read);
	exit(EXIT_FAILURE);
}
