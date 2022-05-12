#include "monty.h"
/**
{
	extern int vari;
	vari = 23;
	err_arg = 1;
	stack_t *stack = NULL;
	void (*fn)(stack_t **, unsigned int);

	printf("test\n");
	fn = inst_sel("push");
	fn(&stack, 4);
}
*/
/**
 * inst_sel - selects a function from inst_list based on input
 * @cmd: command
 * Return: returns a pointer to a function
 */
void (*inst_sel(char *cmd))(stack_t **stack, unsigned int line_number)
{
	int iter = 0;
	char *op_c = NULL;

	instruction_t inst_list[] =
	{
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL},
	};

	if (!cmd)
		return (NULL);

	/* compare */
	op_c = inst_list[iter].opcode;

	while (op_c != NULL)
	{
		if (strcmp(cmd, op_c) == 0)
			return (inst_list[iter].f);
		iter++;
		op_c = inst_list[iter].opcode;
	}
	return (NULL);
}
