#include "monty.h"

void free_dlistint(stack_t *head)
{
        stack_t *c_node, *aux_ptr;

        if (!head)
                return;

        if (head)
        {
                for (c_node = head; c_node->next != NULL;)
                {
                        aux_ptr = c_node->next;
                        free(c_node);
                        c_node = aux_ptr;
                }
                free(c_node);
        }
}
