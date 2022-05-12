#include "monty.h"

/**
*push - add element to the the stack
*@head: pointer to a first element
*@line_number: line number
*/

void push(stack_t **head, unsigned int line_number)
{
	stack_t *new_node = NULL;

	if (err_arg == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		new_node = malloc(sizeof(stack_t));
		if (new_node == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}

		/*if tuviera data debería darle el valor*/
		new_node->n = vari;
		new_node->prev = NULL;
		new_node->next = *head;

		if (*head != NULL)
		{
			(*head)->prev = new_node;
		}

		*head = new_node;
	}
}

/**
*pall - print all the elements in the stack
*@head: pointer at the first node
*@line_number: line_number
*/
void pall(stack_t **head, unsigned int line_number __attribute__((unused)))
{
	stack_t *c_node = NULL;

	/*Lista vacía*/
	if (*head == NULL)
		return;

	c_node = *head;
	while (c_node != NULL)
	{
		printf("%d\n", c_node->n);
		c_node = c_node->next;
	}
}

/**
*pint - print top value of the stack.
*@head: pointer to first node of the list
*@line_number: line number of the file with byte code
*/
void pint(stack_t **head, unsigned int line_number __attribute__((unused)))
{
	stack_t *c_node = *head;

	if (*head != NULL)
	{
		printf("%d\n", c_node->n);
	}
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number");
		exit(EXIT_FAILURE);
	}

}
