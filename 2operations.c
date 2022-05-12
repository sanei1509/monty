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
		exit(EXIT_FAILURE);
	}

	num = (*head)->n;
	*head = (*head)->next;
	/*intercambio de n*/
	(*head)->prev->n = num;
	(*head)->n = num;
	*head = (*head)->prev;
}

/**
 *add - add the last two elements 
 *@head: pointer to the first element
 *@line_number: line number of byte codes
 */
void add(stack_t **head, unsigned int line_number)
{
	stack_t *c_node = *head;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/*guarde referencia asi que puedo mover mi puntero head*/
	*head = (*head)->next;
	/*necesito sumar valores de ambos elementos*/
	(*head)->n = (*head)->n + c_node->n;
	(*head)->prev = NULL;
}

/**
 *nop - do nothing
 *@head: variable not used
 *@line_num
 */
void nop(stack_t **stack __attribute__((unused)), unsigned int line_number __attribute__((unused)))
{
 	/*esto o castear las variables a void para indicarle que no vamos a usarlas*/
}
