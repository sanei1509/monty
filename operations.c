#include "main.h"

/**
*push - add element to the the stack
*@head: pointer to a first element
*@line_number: line number
*/

void push(stack_t **head, unsigned int line_number)
{
	stack_t *element = NULL;
	new_node = malloc(sizeof(stack_t));

	if (element == NULL)
	{
		return(NULL);
	}

	/*if tuviera data debería darle el valor*/
	element->prev = NULL;
	element->next = NULL;
	
	if (*head != NULL)
	{
		(*head)->prev = element;
	}

	if (element != NULL)
	{
		element->next = *head;
		*head = new_node;
	
	}
}

/**
*pall - print all the elements in the stack
*@head: pointer at the first node
*@line_number: line_number
*/
void pall(stack_t **head, unsigned int line_number)
{
	stack_t *aux = NULL;

	/*Lista vacía*/
	if (*head == NULL)
		return;

	aux = *head;
	while (aux != NULL)
	{
		printf("%d\n", tmp->n);
		aux = aux->next;
	}
}

