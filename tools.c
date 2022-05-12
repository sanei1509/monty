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


/**
 * check_atoi - checks if the 0 output of atoi is due to 0 int or error code
 * @str: str
 * Return: 0 sucess, -1 failed
 */
int check_token(char *str)
{
	int i = 0;

	if (!str || str[0] == '\0')
		return (-1);

	if (vari == 0)
	{
		if (str[0] != '0' || str[0] != '-')
			return (-1);

		for (i = 1; str[i] != '\0'; i++)
		{
			if (str[i] != '0')
				return (-1);
		}
	}

	return (0);
}
