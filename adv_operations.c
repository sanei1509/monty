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
		fclose(gl.fp);
		free(gl.line_read);
                exit(EXIT_FAILURE);
        }

        /*guarde referencia asi que puedo mover mi puntero head*/
        *head = (*head)->next;
        /*necesito restar valores de ambos elementos*/
        (*head)->n = (*head)->n - c_node->n;
        (*head)->prev = NULL;
	free(c_node);
}

/**
 *div - div the last two element of the stack
 *@head: pointer
 */

void _div(stack_t **head, unsigned int line_number)
{
	stack_t *c_node = *head;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		fclose(gl.fp);
		free_dlistint(*head);
		free(gl.line_read);
		exit(EXIT_FAILURE);
	}
	
	if (c_node->n == 0)
	{
		fprintf(stderr, "L%u: division by zero", line_number);
		fclose(gl.fp);
		free_dlistint(*head);
		free(gl.line_read);
		exit(EXIT_FAILURE);
	}

	*head = (*head)->next;
	(*head)->n = (*head)->n / c_node->n;
	(*head)->prev = NULL;
	free(c_node);
}



