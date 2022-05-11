#include "monty.h"
#include <stdlib.h>

int main(void)
{
	stack_t *stack = NULL;
	void (*fn)(stack_t **, unsigned int);

	printf("test\n");

	fn = inst_sel("push");
	fn(&stack, 4);
}

/**
 * inst_sel - selects a function from inst_list based on input
 * @comm: command
 * Return: returns a pointer to a function
 */
void (*inst_sel(char *comm))(stack_t **stack, unsigned int line_number)
{
	extern char *vari;
	int iter = 0, ch_it = 0;
	char *op_c = NULL;

	instruction_t inst_list[] =
	{
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL},
	};

	if (!comm)
		return (NULL);
		
	/* compare */
	op_c = inst_list[iter].opcode;

	for (iter = 0; op_c != NULL; iter++, op_c = inst_list[iter].opcode)
	{
		/* iterate through both strings */
		for (ch_it = 0; comm[ch_it] != '\0' || op_c[ch_it] != '\0'; ch_it++)
		{
			/* break loop in case of end of op_c */
			if (op_c[ch_it] == '\0')
				break;

			/* check for differences */
			if (op_c[ch_it])
				break;
		}

		if (comm[ch_it] == op_c[ch_it])
		{
			return (inst_list[iter].f); /* coincidence found */
		}
	}

	return (NULL);
}

void _push(stack_t **stack, unsigned int line_number)
{
	stack = NULL;
	printf("line: %dn", line_number);
}

void _pall(stack_t **stack, unsigned int line_number)
{
	stack = NULL;
	printf("line: %d\n", line_number);
}