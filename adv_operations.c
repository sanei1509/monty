#include "monty.h"

/**
 *sub - substract the las two element of the stack
 *@head: pointer
 */

void sub(stack_t **head, unsigned int line_number)
{
        stack_t *c_node = *head;

        if (*head == NULL || (*head)->next == NULL)
        {
                fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }

        /*guarde referencia asi que puedo mover mi puntero head*/
        *head = (*head)->next;
        /*necesito sumar valores de ambos elementos*/
        (*head)->n = (*head)->n - c_node->n;
        (*head)->prev = NULL;
}

/**
 *div - div the last two element of the stack
 *@head: pointer
 */

void div(stack_t **head, unsigned int line_number)
{
	stack_t *c_node = *head;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr ,"L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	
	*head = (*head)->next;
	(*head)->n = (*head)->n - c_node->n;
	(*head)->prev = NULL;
}


