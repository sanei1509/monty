#include "monty.h"

/**
 *swap - to exchange the las two elements
 *@head: pointer to the first element
 *@line_number: line number of byte codes
 */

void swap(stack_t **head, unsigned int line_number)
{
	int num = 0;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		fclose(gl.fp);
		if (*head)
			free_dlistint(*head);
		free(gl.line_read);
		exit(EXIT_FAILURE);
	}

	num = (*head)->n;
	/*intercambio de n*/
	(*head)->n = (*head)->next->n;
	(*head)->next->n = num;
}
