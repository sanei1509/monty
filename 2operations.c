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
		fclose(gl.fp);
		if (*head)
			free_dlistint(*head);
		free(gl.line_read);
		exit(EXIT_FAILURE);
	}

	/*guarde referencia asi que puedo mover mi puntero head*/
	*head = (*head)->next;
	/*necesito sumar valores de ambos elementos*/
	(*head)->n = (*head)->n + c_node->n;
	(*head)->prev = NULL;
	free(c_node);
}

/**
 * mul - multiplies the last two elements 
 * @head: pointer to the first element
 * @line_number: line number of byte codes
 */
void mul(stack_t **head, unsigned int line_number)
{
	stack_t *c_node = *head;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		fclose(gl.fp);
		if (*head)
			free_dlistint(*head);
		free(gl.line_read);
		exit(EXIT_FAILURE);
	}

	/*guarde referencia asi que puedo mover mi puntero head*/
	*head = (*head)->next;
	/*necesito sumar valores de ambos elementos*/
	(*head)->n = (*head)->n * c_node->n;
	(*head)->prev = NULL;
	free(c_node);
}

/**
 *nop - do nothing
 *@head: variable not used
 *@line_num
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	/*esto o castear las variables a void para indicarle que no vamos a usarlas*/
}
